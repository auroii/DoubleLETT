#include <iostream>
#include <vector>
#include "DoubleLETT.hpp"
#include "Node.hpp"
#include "Edge.hpp"
#include <complex>


using std::vector;
using std::cin;
using std::cout;
using std::complex;


int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;

    vector<Node> nodes;
    for(int i = 0; i < n+1; ++i) {
        nodes.push_back(Node(i+1));
    }
    vector<Edge> edges;

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edges.push_back(Edge(i, nodes[x-1], nodes[y-1]));
    }

    DoubleLETT *t = new DoubleLETT(nodes, edges);


    for(int i = 0; i < t->euler.size(); ++i) cout << t->euler[i].label << ' ';
    cout << '\n';

    for(int i = 0; i < t->len; ++i) {
        cout << i << ": ";
        for(Node x : t->sqrtEuler[i]) {
            cout << x.label << ' ';
        }
        cout << '\n';
    }
    const int STEPS = 100;
    for(int it = 0; it < STEPS; ++it) {
        t->currentCalculation();
    }

    delete t;

    return 0;

}