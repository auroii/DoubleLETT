#include "DoubleLETT.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Node.hpp"

using std::vector;
using std::cout;
using std::min;
using std::make_pair;

#define D(x) cout << #x << " " << x << '\n'

void DoubleLETT::eulerTour(vector<vector<Node>> &g, int node, int h) {
    seen[node] = true;
    height[node] = h;
    first[node] = euler.size();
    
    for(Node to : g[node]) {
        if(!seen[to.label]) {
            euler.push_back(to);
            eulerTour(g, to.label, h+1);
            euler.push_back(to);
        }

    }
}

void DoubleLETT::sqrtDecomposition() {
    int len = sqrt(euler.size() + .0) + 1;
}


DoubleLETT::DoubleLETT(vector<vector<Node> > &g) {
    seen.resize(g.size());
    height.resize(g.size());
    first.resize(g.size());

    eulerTour(g, 1);
    sqrtDecomposition();
}