#include "Node.hpp"
#include <complex>

using std::complex;
using std::conj;

Node::Node(int l, complex<double> _voltage, complex<double> _current, complex<double> _load) {
    voltage = _voltage;
    current = _current;
    load = _load;
    label = l;
}


void Node::updateCurrent() {
    current = conj(load/voltage);
}

