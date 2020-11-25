#ifndef EDGE_HPP
#define EDGE_HPP

#include "Node.hpp"
#include <complex>

using std::complex;

class Edge {
public:
    Node a, b;
    complex<double> impedance;
    int label;
    Edge(int label, Node a, Node b) : label(label), a(a), b(b) {}
    complex<double> getImpedance();

};


#endif


