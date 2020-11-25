#include <vector>
#include <iostream>

using std::vector;
using std::pair;

/*
Class that implements a double level euler tour tree
@height: height of nodes in original tree
@euler: euler tour array
@first: each element is the first apparition index in DFS
@seen: auxiliar array for DFS euler tour
@level2: sqrt decomposition of euler tour array

*/

class DoubleLETT {
private:
    vector<int> height, first, level2;
    vector<pair<int, int>> euler;
    vector<bool> seen;


    void eulerTour(vector<vector<int>> &g, int node, int h = 0);
    void sqrtDecomposition();

public:
    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>> &g);
    

};









