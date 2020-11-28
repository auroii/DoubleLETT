#include <vector>
#include "DoubleLETT.hpp"
#include "Node.hpp"
#include <complex>
#include "Utils.hpp"
#include <unordered_map>

using std::vector;
using std::complex;
using std::unordered_map;

int main(int argc, char **argv) {
    vector<vector<int>> adj;
    unordered_map<pair<int,int>, complex<double>, HashPair> Z;
    complex<double> init;

    readData(adj, Z, init);
    
    DoubleLETT *DLT = new DoubleLETT(adj, Z, init);

    delete DLT;

    return 0;

}


