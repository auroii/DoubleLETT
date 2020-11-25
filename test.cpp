#include <iostream>
#include <vector>
#include "DoubleLETT.hpp"
#include "Node.hpp"
#include <complex>


using std::vector;
using std::cin;
using std::cout;
using std::complex;


int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;
    vector<vector<Node>> g(n + 1, vector<Node>());
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(Node(y));
        g[y].push_back(Node(x));
    }

    DoubleLETT *t = new DoubleLETT(g);
    for(int i = 0; i < t->euler.size(); ++i) cout << t->euler[i].label << ' ';
    cout << '\n';

    for(int i = 0; i < t->len; ++i) {
        cout << i << ": ";
        for(Node x : t->sqrtEuler[i]) {
            cout << x.label << ' ';
        }
        cout << '\n';
    }


    delete t;

    return 0;

}