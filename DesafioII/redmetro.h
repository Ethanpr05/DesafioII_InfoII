#ifndef REDMETRO_H
#define REDMETRO_H
#include <string>
#include "lineas.h"

using namespace std;

class redMetro
{
private:
    string redName;
    int sizeRed, capacidadRed;
    lineas *redsArray;
public:
    redMetro(string _redName,int _sizeRed);
    void showRed();
    void addLine(string lineName, int sizeLine);
    void setRedsArray(int _capacidadRed);
    lineas getredsArray(string &_lineName)const;
};

#endif // REDMETRO_H
