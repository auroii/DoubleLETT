#include "Node.hpp"
#include <complex>

using std::complex;

Node::Node(int l, complex<double> voltage) {
    V = voltage;
    I = 0;
    S = 0;
    label = l;
}