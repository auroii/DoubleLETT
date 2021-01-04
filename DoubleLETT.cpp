#include "DoubleLETT.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Node.hpp"
#include <ctime>
#include <cstdlib>
#include "Utils.hpp"
#include <complex>

using std::vector;
using std::cerr;
using std::min;
using std::make_pair;
using std::complex;
using std::conj;
using std::max;
using std::real;
using std::imag;
using std::polar;



void DoubleLETT::eulerTour(vector<vector<int>> &adj, int node, int d) {
    in[node] = ++T; //timer da meu tempo
    depth[node] = d;
    first[node] = euler.size(); //seto o primeiro indice do array euler que o Node(label) cur aparace
    if(node == ROOT) occ.push_back(euler.size()); //indices de ocorrencias do raiz
    euler.push_back(node);    //insere o label cur no array euler
    for(int to : adj[node]) { //g[cur] contem todos os nos adjacentes a cur 
        if(in[to] == 0) {
            nodeList[node].updateDegree();
            eulerTour(adj, to, d+1);
            if(node == ROOT) occ.push_back(euler.size()); //indices de ocorrencias do raiz
            euler.push_back(node); //usando a pilha de recursão, eu insiro ele novamente
        }
    }
    out[node] = ++T;
}


DoubleLETT::DoubleLETT(vector<vector<int>> &adj, unordered_map<pair<int, int>, complex<double>, HashPair>& _Z, complex<double> init) {
    in.resize(adj.size());
    out.resize(adj.size());
    depth.resize(adj.size());
    first.resize(adj.size());   
    Z.swap(_Z);
    T = 0;
    
    for(int i = 0; i < adj.size(); ++i) {
        nodeList.emplace_back(i);
    }
    eulerTour(adj, ROOT, 0);

    /*for(int x : euler) cerr << x << ' ';
    cerr << '\n';

    for(int i = 0; i < euler.size(); ++i) {
        cerr << euler[i] << ' ' << euler[i+1] << ": " << isAncestor(euler[i], euler[i+1]) << '\n';
    }*/
    
    for(int i = 0; i < euler.size(); ++i) {
        nodeList[euler[i]].setVoltage(init);
    }

    doubleEulerTour.resize(occ.size()-1);

    for(int i = 0; i < doubleEulerTour.size(); ++i) {
        for(int j = occ[i]; j <= occ[i+1]; ++j) {
            doubleEulerTour[i].push_back(euler[j]);
        }    
    }

    for(auto v : doubleEulerTour) {
        for(int x : v) {
            cerr << x << ' ';
        }
        cerr << '\n';
    }


    maxDiffReactivePower = maxDiffRealPower = 0;
    precision = 1e-9;
}

void DoubleLETT::updateLoadNode(int label, complex<double> powerload) {
    
    nodeList[label].setPowerLoad(powerload);

    updateMaxDiffRealPower(nodeList[label]);
    updateMaxDiffReactivePower(nodeList[label]);

    while(getMaxDiffReactivePower() > precision || getMaxDiffRealPower() > precision) {
        totalChargeFlow();
    }
}


void DoubleLETT::updateLoadNode(int label, double M, double T) {
    updateLoadNode(label, polar(M, T));
}


void DoubleLETT::setPrecision(double p) {
    precision = p;
}

double DoubleLETT::getPrecision() {
    return precision;
}

double DoubleLETT::getMaxDiffReactivePower() {
    return maxDiffReactivePower;
}

double DoubleLETT::getMaxDiffRealPower() {
    return maxDiffRealPower;
}

void DoubleLETT::updateMaxDiffReactivePower(Node &node) {
    maxDiffReactivePower = max(maxDiffReactivePower, fabs(imag(node.getDiffPowerLoad())));
}

void DoubleLETT::updateMaxDiffRealPower(Node &node) {
    maxDiffRealPower = max(maxDiffRealPower, fabs((real(node.getDiffPowerLoad()))));
}


bool DoubleLETT::isAncestor(int u, int v) {
    return(in[u] <= in[v] && out[u] >= out[v]);
}



void DoubleLETT::totalChargeFlow() {
    for(int i = 0; i <  doubleEulerTour.size(); ++i) {
        subChargeFlow(i);
    }
}


void DoubleLETT::subChargeFlow(int id) {

    vector<int> &block = doubleEulerTour[id];

    for(int it : block) {
        nodeList[it].updateGNDCurrent();
    }
    for(int i = 0; i < block.size()-1; ++i) { 
        if(isAncestor(block[i+1], block[i])) {
            //block[i] é o label e o indice simulteneamente do nó atual do array euler
            nodeList[block[i+1]].addCurrentDownstream(nodeList[block[i]].getTotalCurrent());
        }
    }

    for(int i = 1; i < block.size(); ++i) {
        if(isAncestor(block[i-1], block[i])) {
            nodeList[block[i]].
        setVoltage(nodeList[block[i-1]].getVoltage() 
        - Z[{block[i], block[i-1]}]*nodeList[block[i]].getCurrentDownstream());
        }
    }
    maxDiffReactivePower = 0;
    maxDiffRealPower = 0;
    for(int it : block) {
        updateMaxDiffReactivePower(nodeList[it]);
        updateMaxDiffRealPower(nodeList[it]);
    }
}


void DoubleLETT::dump() {
    cerr << "occ = ";
    for(int x : occ) cerr << x << ' ';
    cerr << '\n';

    for(int x : euler) cerr << x << ' ';
    cerr << '\n';

    for(int i = 0; i < euler.size(); ++i) {
        cerr << euler[i] << ' ' << euler[i+1] << ": " << isAncestor(euler[i], euler[i+1]) << '\n';
    }


    for(int i = 1; i < nodeList.size(); ++i) {
        cerr << "Node: " << nodeList[i].getLabel() << '\n';
        cerr << "Id = ";
        printPolar(nodeList[i].getCurrentDownstream());
        cerr << "I = ";
        printPolar(nodeList[i].getCurrent());
        cerr << "V = ";
        printPolar(nodeList[i].getVoltage());
        cerr << "S = ";
        printPolar(nodeList[i].getPowerLoad());
        cerr << "dif = ";
        printPolar(nodeList[i].getDiffPowerLoad());
    }
}