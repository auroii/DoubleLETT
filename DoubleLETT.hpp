#ifndef DOUBLE_LETT_HPP
#define DOUBLE_LETT_HPP

#include <vector>
#include <iostream>
#include "Node.hpp"

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
public: //for now
    vector<int> height, first, level2;
    vector<Node> euler;
    vector<bool> seen;


    void eulerTour(vector<vector<Node>>& g, int node,  int h = 0);
    void sqrtDecomposition();

    DoubleLETT(void) {}
    DoubleLETT(vector<vector<Node>> &g);


};

#endif







