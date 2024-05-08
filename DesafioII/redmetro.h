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
   // void setRedsArray(int _capacidadRed);
    void lineFinder(string _lineName)const;
    void lineFinder(string &_lineName, string &_nameStation)const;
    int getCantLines()const;
    int howManyStat()const;
    lineas *getLinea(string &_lineName) const;
    void delLine(const string _lineName);
    bool lineaExist(string &lineName);
    ~redMetro();
};

#endif // REDMETRO_H
