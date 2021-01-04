#ifndef NODE_HPP
#define NODE_HPP

#include <complex>


using std::complex;



class Node {
private:
    complex<double> current; //current // corrente incidente
    complex<double> currentDownstream;
    complex<double> voltage; //voltage
    complex<double> load; //desire load power 
    int label; //label inteiros pois suas operações lógicas são muito rapidas
    int degree;
public:

    Node(int _label, complex<double> voltage = complex<double>(0, 0),
     complex<double> current = complex<double>(0, 0),
      complex<double> load = complex<double>(0, 0));


    void updateGNDCurrent();

    complex<double> getDiffPowerLoad();
    complex<double> getPowerLoad();
    complex<double> getVoltage();
    complex<double> getCurrent();
    complex<double> getCurrentDownstream();
    complex<double> getTotalCurrent();
    int getDegree();
    int getLabel();

    void addCurrentDownstream(complex<double> I);
    void updateDegree();
    void setPowerLoad(complex<double> _load); //set a potencia deste no
    void setCurrent(complex<double> _current);
    void setVoltage(complex<double> _voltage);
};


#endif