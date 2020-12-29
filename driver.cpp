#include <vector>
#include "DoubleLETT.hpp"
#include "Node.hpp"
#include <complex>
#include "Utils.hpp"
#include <unordered_map>
#include <cmath>
#include <iostream>

using std::cerr;
using std::vector;
using std::complex;
using std::unordered_map;

const double PI = acos(-1);

int main(int argc, char **argv) {
    vector<vector<int>> adj; 

    unordered_map<pair<int,int>, complex<double>, HashPair> Z; //lista vs hash desempenho
    
    complex<double> init;

    readData(adj, Z, init);

    DoubleLETT *DLT = new DoubleLETT(adj, Z, init);


    DLT->updateLoadNode(5, 100, PI/2);
    DLT->updateLoadNode(2, 300, PI);
    DLT->dump();

    delete DLT;

    return 0;

}


