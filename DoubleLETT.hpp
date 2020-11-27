#ifndef DOUBLE_LETT_HPP
#define DOUBLE_LETT_HPP

#include <vector>
#include <iostream>
#include "Node.hpp"
#include <map>

using std::vector;
using std::pair;
using std::complex;
using std::map;

class DoubleLETT {
private: //for now
    vector<int> depth, first; //TODO last
    vector<int> euler;
    vector<int> in, out;
    vector<Node> nodeList;
    int T; //timer in DFS
    map<pair<int, int>, complex<double>> Z;
    void eulerTour(vector<vector<int>>& adj, int node, int d = 0);
    double precision;


public:
    void updateLoadNode(int _label, complex<double> _load);
    
    double getPrecision();
    void setPrecision(double);

    void chargeFlow();

    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>>& adj, map<pair<int, int>, complex<double>>& Z,
     complex<double> init = complex<double>(0, 0));
    //~DoubleLETT();

};

#endif
