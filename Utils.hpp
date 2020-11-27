#ifndef UTILS_HPP
#define UTILS_HPP

#define ROOT 1

#include <vector>
#include <complex>
#include <map>

using std::vector;
using std::complex;
using std::map;
using std::pair;


void readData(vector<vector<int>> &adj, map<pair<int, int>, complex<double>>& Z,
     complex<double>& init);



#endif