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
    void delStation();
    int getlinesArray();
    int howManyStat();
    string getLineName()const;
    bool statBelongs(string nameStat);
    void operator=(const lineas& otraLinea);
    void existe(string _lineName);
    void mostrar();
    void setSize(int _sizeLine);
    void setlinesArray(int _capacidadLine);
    void statFinder(string nameStatOrig, string nameStatprev);
    ~lineas();
};

#endif // LINEAS_H
