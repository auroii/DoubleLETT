#include <iostream>
#include <vector>
#include "DoubleLETT.hpp"

using std::vector;
using std::cin;
using std::cout;


void dfs(vector<vector<int>> &g, vector<int>& vis, int v) {
    vis[v] = true;

    for(int u : g[v]) {
        if(!vis[u]) {
            dfs(g, vis, u);
        }
    }
} 


int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>());

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> vis(n+1);
    dfs(g, vis, 1);


    DoubleLETT *t = new DoubleLETT(g);

    delete t;

    return 0;

}