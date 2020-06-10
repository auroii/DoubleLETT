#include <vector>
#include <iostream>

using std::vector;


/*
Class with implements a double level euler tour tree
@height: height of nodes in original tree
@euler: euler tour array, TODO: each element represents an edge instead nodes
@first: each element is the first apparition index in DFS
@seen: auxiliar array for DFS euler tour
@level2: sqrt decomposition of euler tour array

*/

class DoubleLETT {
private:
    vector<int> height, euler, first; 
    vector<bool> seen;
    vector<int> level2;
    void eulerTour(vector<vector<int>> &g, int node, int h = 0);
    void sqrtDecomposition();

public:
    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>> &g);


};