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
    void delStation(const string &nameStation);
    int getSizeLine();
    string getLineName()const;
    bool statBelongs(string nameStat);
    void operator=(const lineas &otraLinea);
    void mostrar();
    void setSize(int _sizeLine);
    void statFinder(string nameStatOrig, string nameStatprev);
    void compareStat(string NameSt);
    bool tieneTransf();
    ~lineas();
};

#endif // LINEAS_H
