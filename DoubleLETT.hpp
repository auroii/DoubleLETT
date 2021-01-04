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
    vector<int> euler; //tamanho euler =  O(maxdegree*N) e maxdegree = O(sqrtN)
    vector<int> in, out;
    vector<int> occ;
    vector<Node> nodeList; //O(N) --> acessar o no de label 5, basta chamar nodeList[5] 
    vector<vector<int>> doubleEulerTour;
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
    double getMaxDiffReactivePower(); //atualizar para polar // potencia aparente  
    void updateMaxDiffRealPower(Node &);
    void updateMaxDiffReactivePower(Node &);

	bool isAncestor(int u, int v); //O(1)

	void dump();

    void subChargeFlow(int id);
    void totalChargeFlow();

    DoubleLETT(void) {}
    DoubleLETT(vector<vector<int>>& adj, unordered_map<pair<int, int>, complex<double>, HashPair>& Z,
     complex<double> init = complex<double>(0, 0));
    //~DoubleLETT();

};

#endif
