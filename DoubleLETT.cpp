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

void DoubleLETT::eulerTour(vector<vector<int>> &g, int cur, int h) {
    in[cur] = ++T;
    height[cur] = h;
    first[cur] = euler.size();
    euler.push_back(cur);   
    for(int to : g[cur]) {
        if(in[to] == 0) {
            eulerTour(g, to, h+1);
            euler.push_back(cur);
        }
    }
    out[cur] = ++T;
}

void DoubleLETT::sqrtDecomposition() {
    len = sqrt(euler.size() + .0) + 1;
    sqrtEuler.resize(len);
    for(int i = 0; i < euler.size(); ++i) {
        sqrtEuler[i/len].push_back(euler[i]);
    }
}


DoubleLETT::DoubleLETT(vector<Node>& nodes, vector<Edge>& edges, complex<double> init) {
    in.resize(nodes.size());
    out.resize(nodes.size());
    height.resize(nodes.size());
    first.resize(nodes.size());   
    T = 0;
    vector<vector<int>> g(nodes.size(), vector<int>());
    for(int i = 0; i < edges.size(); ++i) { 
        Edge cur = edges[i];
        g[cur.a.label].push_back(cur.b.label);
        g[cur.b.label].push_back(cur.a.label);
    }

    eulerTour(g,  1);

    for(int i = 0; i < euler.size(); ++i) {
        euler[i].voltage = init;
        euler[i].load = complex<double>(1, 1);
    }
    sqrtDecomposition();
}


void DoubleLETT::currentCalculation() {
    for(int i = 0; i < euler.size(); ++i) {
        euler[i].updateCurrent();
    }
}





