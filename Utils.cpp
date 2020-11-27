#include <vector>
#include <map>
#include <complex>
#include <iostream>
#include "Utils.hpp"

using std::pair;
using std::vector;
using std::complex;
using std::map;
using std::cin;
using std::polar;




void readData(vector<vector<int>>& adj, map<pair<int, int>, complex<double>> &Z, complex<double>& init) {
    int n, m;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        double zm, zt;
        cin >> zm >> zt;
        Z[{x, y}] = Z[{y, x}] = polar(zm, zt);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    double im, it;
    cin >> im >> it;
    init = polar(im, it);
}



