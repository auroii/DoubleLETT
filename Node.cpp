#include "Node.hpp"
#include <complex>

using std::complex;

Node::Node(complex<double> voltage, int l) {
    V = voltage;
    I = 0;
    S = 0;
    label = l;
}