#ifndef LINEAS_H
#define LINEAS_H
#include <string>
#include "estaciones.h"

using namespace std;

class lineas
{
private:
    string lineName;
    int sizeLine, capacidadLine;
    estaciones *linesArray;

public:
    lineas(string _lineName, int _sizeLine);
    lineas();
    void addStation();
    void addStation(int howMany);
    void delStation();
    int getlinesArray();
    int howManyStat();
    bool statBelongs();
    void operator=(const lineas& otraLinea);
    void existe();
    void mostrar();
    void setSize(int _sizeLine);
    string calcTiempo();
    ~lineas();
};

#endif // LINEAS_H
