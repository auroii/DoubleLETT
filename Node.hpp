#ifndef NODE_HPP
#define NODE_HPP

#include <complex>


using std::complex;

class Node {
public:
    complex<double> current; //current
    complex<double> voltage; //voltage
    complex<double> load;; //load power
    int label;
    Node(int l, complex<double> voltage = complex<double>(1, 1),
     complex<double> current = complex<double>(1, 1),
      complex<double> load = complex<double>(1, 1));

    void updateCurrent();

};


#endif