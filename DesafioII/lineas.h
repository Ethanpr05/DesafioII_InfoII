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
    void addStation(lineas &line);
    void delStation();
    int getlinesArray();
    int howManyStat();
    string getName()const;
    bool statBelongs();
    void operator=(const lineas& otraLinea);
    void existe(string _lineName);
    void mostrar();
    void setSize(int _sizeLine);
    bool getcompare(string _lineName);
    string calcTiempo();
    ~lineas();
};

#endif // LINEAS_H
