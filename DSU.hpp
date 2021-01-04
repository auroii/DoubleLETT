#ifndef DSU_HPP
#define DSU_HPP

#include <vector>

using std::vector;

class DSU {
private:
    vector<int> parent, rank, size;
public:
    DSU() {}
    DSU(int N);
    int find(int cur);
    bool join(int v, int u);
    bool sameTree(int v, int u);
};




#endif