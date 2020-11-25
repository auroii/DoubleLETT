#ifndef NODE_HPP
#define NODE_HPP

#include <complex>


using std::complex;

class Node {
public:
    complex<double> I; //current
    complex<double> V; //voltage
    complex<double> S; //load power
    int label;
    Node(complex<double> voltage, int l);
};


#endif