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

public:
    estaciones();
    estaciones(string _nameStation, int _timePrev, int _timeNext);
    /*estaciones(string _nameStation, int _timePrev);
    estaciones(string _nameStation, int _timeNext);*/
    void operator=(const estaciones& otraEstacion);
    void setnameStation(string _nameStation);
    string getNameStation() const;
    void setTimePrev(int _timePrev);
    int getTimePrev() const;
    void mostrarSt();
    void setTimeNext(int _timeNext);
    int getTimeNext() const;
    //void setDeleteStation(string _nameStation);
    ~estaciones();

};

#endif // ESTACIONES_H
