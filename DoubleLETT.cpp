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


//Heavy Light Decomposition -> pesquisar


void DoubleLETT::eulerTour(vector<vector<int>> &adj, int node, int d) {
    in[node] = ++T; //timer da meu tempo
    depth[node] = d;
    first[node] = euler.size(); //seto o primeiro indice do array euler que o Node(label) cur aparace
    euler.push_back(node);    //insere o label cur no array euler
    for(int to : adj[node]) { //g[cur] contem todos os nos adjacentes a cur 
        if(in[to] == 0) {
            nodeList[node].updateDegree();
            eulerTour(adj, to, d+1);
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
    for(int x : euler) cerr << x << ' ';
    cerr << '\n';
    for(int i = 0; i < euler.size(); ++i) {
        nodeList[euler[i]].setVoltage(init);
    }

    maxDiffReactivePower = maxDiffRealPower = 0;
    precision = 1e-9;
}

void DoubleLETT::updateLoadNode(int label, complex<double> powerload) {
    nodeList[label].setPowerLoad(powerload);

    while(getMaxDiffReactivePower() > precision || getMaxDiffRealPower() > precision) {
        chargeFlow();
    }
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
    maxDiffReactivePower = max(maxDiffReactivePower, imag(node.getDiffPowerLoad()));
}

void DoubleLETT::updateMaxDiffRealPower(Node &node) {
    maxDiffRealPower = max(maxDiffRealPower, real(node.getDiffPowerLoad()));
}



void DoubleLETT::chargeFlow() {
    for(int i = 0; i < nodeList.size(); ++i) {
        nodeList[i].updateGNDCurrent();
    }

}






