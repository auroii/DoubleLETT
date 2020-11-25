#ifndef DOUBLE_LETT_HPP
#define DOUBLE_LETT_HPP

#include <vector>
#include <iostream>
#include "Node.hpp"
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
    vector<complex<double>> voltages;
    int T, len; //timer in DFS

    vector<list<Node>> sqrtEuler;

    void eulerTour(vector<vector<Node>>& g, Node cur, int h = 0);
    void sqrtDecomposition();

    DoubleLETT(void) {}
    DoubleLETT(vector<vector<Node>> &g, complex<double> init = complex<double>(0, 0));
    //~DoubleLETT();

};

#endif







