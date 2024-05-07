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
    void lineFinder(string _lineName)const;
    ~redMetro();
};

#endif // REDMETRO_H
