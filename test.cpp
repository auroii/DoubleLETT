#include <iostream>
#include <vector>
#include "DoubleLETT.hpp"

using std::vector;
using std::cin;
using std::cout;


int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    DoubleLETT *t = new DoubleLETT(g);

    delete t;

    return 0;

}