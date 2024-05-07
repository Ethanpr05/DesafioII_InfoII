#include "redmetro.h"


redMetro::redMetro(string _redName, int _sizeRed)
{
    redName = _redName;
    sizeRed = _sizeRed;
    redsArray = new lineas[sizeRed];
    for (int i=0;i<sizeRed;i++){
        string lineName;
        int sizeLine;
        cout<<"Ingrese el nombre de la linea: "<<endl;
        cin.ignore();
        getline(cin, lineName);
        cout << "Cuantas estaciones desea agregar inicialmente: "<<endl;
        cin>>sizeLine;
        cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina"<<endl;
        redsArray[i]=lineas (lineName, sizeLine);
        cout<<"Listo"<<endl;
    }
}

void redMetro::showRed()
{
    cout << redName << endl;
    for (int i=0;i<sizeRed;i++){
        redsArray[i].mostrar();
    }
}

void redMetro::setRedsArray(int _capacidadRed){
    delete[] redsArray;
    lineas *redsArray = new lineas[_capacidadRed];
}

void redMetro::addLine(string lineName, int sizeLine)
{

    if (sizeRed >= capacidadRed) {
        // Si el arreglo está lleno, aumentar su capacidad
        if (capacidadRed == 0 ) {
            capacidadRed = 1;
        }
        while(sizeRed>=capacidadRed){
            capacidadRed *= 2;
        }
        lineas *nuevoArreglo = new lineas[capacidadRed];
        // Copiar los elementos al nuevo arreglo
        for (int i = 0; i < sizeRed; i++) {
            nuevoArreglo[i] = redsArray[i];
        }
        setRedsArray(capacidadRed);

        for (int i = 0; i < sizeRed; i++) {
            redsArray[i] = nuevoArreglo[i];
        }
       // delete[] nuevoArreglo;
    }
    // Agregar el nuevo elemento al final del arreglo
    redsArray[sizeRed] = lineas(lineName, sizeLine);
    sizeRed++;
}

void redMetro::lineFinder(string _lineName)const {

    for (int i=0;i<sizeRed;i++){
        if(redsArray[i].getLineName==_lineName){
            redsArray[i].mostrar();
            redsArray[i].addStation();
            break;}
    }
}

int redMetro::getCantLines() const{
    return sizeRed;
}

lineas redMetro::getLinea(string _lineName) const{
    for (int i=0;i<sizeRed;i++){
        if(redsArray[i].getLineName()==_lineName){
            break;}
        return redsArray[i];
    }
}

redMetro::~redMetro()
{
    delete[]redsArray;
}
