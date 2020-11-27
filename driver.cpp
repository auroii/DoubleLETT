#include <iostream>
#include <vector>
#include "DoubleLETT.hpp"
#include "Node.hpp"
#include <complex>
#include "Utils.hpp"

using std::vector;
using std::complex;


int main(int argc, char **argv) {
    vector<vector<int>> adj;
    map<pair<int,int>, complex<double>> Z;
    complex<double> init;

    readData(adj, Z, init);
    
    DoubleLETT *DLT = new DoubleLETT(adj, Z, init);

    delete DLT;

    return 0;

}


