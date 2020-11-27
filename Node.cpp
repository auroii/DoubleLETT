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

complex<double> Node::getPowerLoad() {
    return voltage * conj(current);
}

complex<double> Node::getVoltage() {
    return voltage;
}
complex<double> Node::getCurrent() {
    return current;
}

int Node::getLabel() {
    return label;
}



void Node::setPowerLoad(complex<double> _load) {
    load = _load;
}
void Node::setVoltage(complex<double> _voltage) {
    voltage = _voltage;
}
void Node::setCurrent(complex<double> _current) {
    current = _current;
}




