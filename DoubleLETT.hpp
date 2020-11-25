#ifndef DOUBLE_LETT_HPP
#define DOUBLE_LETT_HPP

#include <vector>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"
#include <list>

using std::vector;
using std::pair;
using std::complex;
using std::list;


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
    vector<int> height, first;
    vector<Node> euler;
    vector<int> in, out;
    int T, len; //timer in DFS

    vector<list<Node>> sqrtEuler;

    void eulerTour(vector<vector<int>>& g, int cur, int h = 0);
    void sqrtDecomposition();
    void currentCalculation();
    DoubleLETT(void) {}
    DoubleLETT(vector<Node>& nodes, vector<Edge> &edges, complex<double> init = complex<double>(0, 0));
    //~DoubleLETT();

};

#endif
