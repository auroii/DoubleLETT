#include "DoubleLETT.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::vector;
using std::cout;
using std::min;

#define D(x) cout << #x << " " << x << '\n'

void DoubleLETT::eulerTour(vector<vector<int>> &g, int node, int h) {
    seen[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);

    for(int to : g[node]) {
        if(!seen[to]) {
            eulerTour(g, to, h+1);
            euler.push_back(node);
        }

    }
}

void DoubleLETT::sqrtDecomposition() {
    int len = sqrt(euler.size() + .0) + 1;
    level2.resize(len);
    
    for(int i = 0; i < len; ++i) {
        level2[i] = i*len;
    }

    /*TEST 
    D(len);
    for(int x : euler) cout << x << ' ';
    cout << '\n';

    for(int x : level2) {
        cout << x << ": ";
        for(int i = x; i < min((int) euler.size(), x+len); ++i) {
            cout << euler[i] << ' ';
        }
        cout << '\n';
    }*/
}


DoubleLETT::DoubleLETT(vector<vector<int> > &g) {
    seen.resize(g.size());
    height.resize(g.size());
    first.resize(g.size());

    eulerTour(g, 1);
    sqrtDecomposition();
}