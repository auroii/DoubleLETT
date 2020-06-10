#include "DoubleLETT.hpp"
#include <vector>

using std::vector;



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



DoubleLETT::DoubleLETT(vector<vector<int> > &g) {
    seen.resize(g.size());
    height.resize(g.size());
    first.resize(g.size());
}