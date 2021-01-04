#include "DSU.hpp"
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

DSU::DSU(int N) {
    parent.resize(N+1);
    size.resize(N+1);
    rank.resize(N+1);
    for(int i = 0; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}


int DSU::find(int cur) {
    if(cur == parent[cur]) return cur;
    return parent[cur] = find(cur);
}


bool DSU::join(int v, int u) {
    v = find(v);
    u = find(u);
    if(u == v) return false;

    if(rank[v] < rank[u]) swap(v, u);
    if(rank[v] == rank[u]) rank[v]++;
    parent[u] = v;
    size[v] += size[u];
}


bool DSU::sameTree(int v, int u) {
    return (find(v) == find(u));
}












