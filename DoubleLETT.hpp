#ifndef DOUBLE_LETT_HPP
#define DOUBLE_LETT_HPP

#include <vector>
#include <iostream>
#include "Node.hpp"
#include <unordered_map>
#include "Utils.hpp"

using std::vector;
using std::pair;
using std::complex;
using std::unordered_map;

class DoubleLETT {
private: //for now
    vector<int> depth, first; //TODO last
    vector<int> euler;
    vector<int> in, out;
    vector<Node> nodeList;
    int T; //timer in DFS
    unordered_map<pair<int, int>, complex<double>, HashPair> Z;
    void eulerTour(vector<vector<int>>& adj, int node, int d = 0);
    double precision;
    double maxDiffRealPower;
    double maxDiffReactivePower;

public:
    void updateLoadNode(int _label, complex<double> _load);
    void updateLoadNode(int _label, double M, double T);
    double getPrecision();
    void setPrecision(double);

    double getMaxDiffRealPower();
    double getMaxDiffReactivePower();
    void updateMaxDiffRealPower(Node &);
    void updateMaxDiffReactivePower(Node &);

	bool isAncestor(int u, int v);

	void dump();

    void chargeFlow(vector<int> &block	);

    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>>& adj, unordered_map<pair<int, int>, complex<double>, HashPair>& Z,
     complex<double> init = complex<double>(0, 0));
    //~DoubleLETT();

};

#endif
