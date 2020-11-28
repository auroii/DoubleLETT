#ifndef UTILS_HPP
#define UTILS_HPP

#define ROOT 1

#include <vector>
#include <complex>
#include <unordered_map>


using std::vector;
using std::complex;
using std::unordered_map;
using std::pair;
using std::hash;

struct HashPair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

void printPolar(complex<double> z);


void readData(vector<vector<int>> &adj, unordered_map<pair<int, int>, complex<double>, HashPair>& Z,
     complex<double>& init);



#endif