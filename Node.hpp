#ifndef NODE_HPP
#define NODE_HPP

#include <complex>


using std::complex;



class Node {
private:

    complex<double> current; //current // corrente incidente
    complex<double> voltage; //voltage
    complex<double> load; //desire load power 
    int label; //label inteiros pois suas operações lógicas são muito rapidas

public:

    Node(int _label, complex<double> voltage = complex<double>(0, 0),
     complex<double> current = complex<double>(0, 0),
      complex<double> load = complex<double>(0, 0));


    void updateCurrent();


    complex<double> getPowerLoad();
    complex<double> getVoltage();
    complex<double> getCurrent();
    int getLabel();

    void setPowerLoad(complex<double> _load); //set a potencia deste no
    void setCurrent(complex<double> _current);
    void setVoltage(complex<double> _voltage);
};


#endif