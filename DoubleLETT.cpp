#include "DoubleLETT.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::vector;
using std::cout;
using std::min;
using std::make_pair;

#define D(x) cout << #x << " " << x << '\n'

void DoubleLETT::eulerTour(vector<vector<int>> &g, int node, int h) {
    seen[node] = true;
    height[node] = h;
    first[node] = euler.size();
    for(int to : g[node]) {
        if(!seen[to]) {
            euler.push_back(make_pair(node, to));
            eulerTour(g, to, h+1);
            euler.push_back(make_pair(to, node));
        }

    }
}

void DoubleLETT::sqrtDecomposition() {
    int len = sqrt(euler.size() + .0) + 1;
    level2.resize(len);
    
    for(int i = 0; i < len; ++i) {
        level2[i] = i*len;
    }

    while(level2.back() >= euler.size()) level2.pop_back();


    //----------TEST---------------------------
    D(len);
    cout << "EULER TOUR:  ";
    for(pair<int, int> x : euler) cout << "(" << x.first << " " << x.second << ") ";
    cout << "\n\n";

    cout << "SQRT DECOMPOSITION:\n";
    for(int x : level2) {
        cout << "2LVL INDEX: " << x << ": ";
        for(int i = x; i < min((int) euler.size(), x+len); ++i) {
            cout << "(" << euler[i].first << ' ' << euler[i].second << ") ";
        }
        cout << '\n';
    }
    //END OF TEST--------------------------------------------------
}


DoubleLETT::DoubleLETT(vector<vector<int> > &g) {
    seen.resize(g.size());
    height.resize(g.size());
    first.resize(g.size());

    eulerTour(g, 1);
    sqrtDecomposition();
}