#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <string>
#include <iostream>

using namespace std;

class estaciones
{
private:
    string nameStation;
    int timePrev;
    int timeNext;
    bool transferencia;

public:
    estaciones();
    estaciones(string _nameStation, int _timePrev, int _timeNext);
    void operator=(const estaciones& otraEstacion);
    void setnameStation(string _nameStation);
    string getNameStation() const;
    void setTimePrev(int _timePrev);
    int getTimePrev() const;
    void mostrarSt();
    void setTimeNext(int _timeNext);
    int getTimeNext() const;
    int calcTiempo(int calcTime) const;
    void convertirTransferencia(string lineName);
    bool getTransferencia();

    ~estaciones();

};

#endif // ESTACIONES_H
