#include "DoubleLETT.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Node.hpp"
#include <ctime>
#include <cstdlib>

using std::vector;
using std::cout;
using std::min;
using std::make_pair;
using std::complex;
using std::conj;

void DoubleLETT::eulerTour(vector<vector<Node>> &g, Node cur, int h) {
    in[cur.label] = ++T;
    height[cur.label] = h;
    first[cur.label] = euler.size();
    euler.push_back(cur);   
    for(Node to : g[cur.label]) {
        if(in[to.label] == 0) {
            eulerTour(g, to, h+1);
            euler.push_back(cur);
        }
    }
    out[cur.label] = ++T;
}

void DoubleLETT::sqrtDecomposition() {
    len = sqrt(euler.size() + .0) + 1;
    sqrtEuler.resize(len);
    for(int i = 0; i < euler.size(); ++i) {
        sqrtEuler[i/len].push_back(euler[i]);
    }



}


DoubleLETT::DoubleLETT(vector<vector<Node> > &g, complex<double> init) {
    in.resize(g.size());
    out.resize(g.size());
    height.resize(g.size());
    first.resize(g.size());
    voltages.resize(g.size());
    currents.resize(g.size());
    powerLoads.resize(g.size());
    T = 0;
    srand(time(NULL));
    for(int i = 0; i < voltages.size(); ++i) {
        voltages[i] = init;
        powerLoads[i] = complex<double>(rand()%100 + 10, rand()%100+10);
    }
    eulerTour(g, Node(1));
    sqrtDecomposition();
}


void DoubleLETT::currentCalculation() {
    for(int i = 0; i < currents.size(); ++i) {
        currents[i] = conj(powerLoads[i]/voltages[i]);
    }
}





