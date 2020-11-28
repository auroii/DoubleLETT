#include "Node.hpp"
#include <complex>

using std::complex;
using std::conj;

Node::Node(int l, complex<double> _voltage, complex<double> _current, complex<double> _load) {
    voltage = _voltage;
    current = _current;
    load = _load;
    label = l;
    degree = 0;
}

void Node::updateGNDCurrent() {
    current = conj(load/voltage);
}

complex<double> Node::getPowerLoad() {
    return voltage * conj(current);
}

complex<double> Node::getDiffPowerLoad() {
    return getPowerLoad() - load;
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

int Node::getDegree() {
    return degree;
}

void Node::updateDegree() {
    degree++;
}

complex<double> Node::getCurrentDownstream() {
    return currentDownstream;
}

void Node::addCurrentDownstream(complex<double> I) {
    currentDownstream += I;
}








