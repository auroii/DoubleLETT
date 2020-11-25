#include <iostream>
#include <vector>
#include "DoubleLETT.hpp"
#include "Node.hpp"
#include <complex>

using std::vector;
using std::cin;
using std::cout;
using std::complex;


void dfs(vector<vector<Node>> &g, vector<int>& vis, int v) {
    vis[v] = true;

    for(Node u : g[v]) {
        if(!vis[u.label]) {
            dfs(g, vis, u.label);
        }
    }
} 


int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;

    vector<vector<Node>> g(n + 1, vector<Node>());
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(Node(complex<double>(0, 0), y));
        g[y].push_back(Node(complex<double>(0, 0), x));
    }

    vector<int> vis(n+1);
    dfs(g, vis, 1);


    DoubleLETT *t = new DoubleLETT(g);

    delete t;

    return 0;

}