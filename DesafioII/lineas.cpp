#include "lineas.h"


lineas::lineas(string _lineName, int _sizeLine) {
    lineName = _lineName;
    sizeLine = _sizeLine;
    capacidadLine = sizeLine;
    while(sizeLine>=capacidadLine){
        capacidadLine *= 2;
    }
    linesArray = new estaciones[capacidadLine];
    string NameSt;
    int TimeP, TimeN;
    for(int i=0;i<sizeLine;i++){

        cout << "Ingrese el nombre de la estacion: "<<endl;
        cin.ignore();
        getline(cin,NameSt);
        cout << "Ingrese el tiempo a la estacion siguiente: "<<endl;
        cin>>TimeN;
        cout << "Ingrese el tiempo a la estacion anterior: "<<endl;
        cin>>TimeP;
        linesArray[i]=estaciones(NameSt, TimeP, TimeN);
        cout<<"Listo estacion creada"<<endl;
    }
}

lineas::lineas()
{
    lineName = "";
    sizeLine = 1;
    capacidadLine = sizeLine*2;
    linesArray = nullptr;
}

void lineas::addStation()
{
    string NameSt, NameSp;
    int TimeP, TimeN, cont=0;
    cout << "Ingrese el nombre de la estacion: "<<endl;
    //cin.ignore();
    getline(cin,NameSt);
    cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina"<<endl;
    cout << "Ingrese el tiempo a la estacion siguiente: "<<endl;
    cin>>TimeN;
    cout << "Ingrese el tiempo a la estacion anterior: "<<endl;
    cin>>TimeP;
    if(TimeN!=0 && TimeP!=0){
        cout << "Ingrese el nombre de la estacion que se encontrara antes que la nueva estacion "<<endl;
        cin.ignore();
        getline(cin,NameSp);
    }
    sizeLine++;
    if (sizeLine >= capacidadLine) {
        // Si el arreglo está lleno, aumentar su capacidad
        /*if (capacidadLine == 0) {
            capacidadLine = 1;
        }*/
        capacidadLine *= 2;
        estaciones *nuevoArreglo = new estaciones[capacidadLine];
        // Copiar los elementos al nuevo arreglo
        for (int i = 0; i < sizeLine-1; i++) {
            if(TimeP==0){
                nuevoArreglo[i] = estaciones(NameSt, TimeP, TimeN);
            }
            else if(TimeN==0){
                nuevoArreglo[capacidadLine-1] = estaciones(NameSt, TimeP, TimeN);
            }
            else if(linesArray[i].getNameStation()==NameSp){
                nuevoArreglo[i+1] = estaciones(NameSt, TimeP, TimeN);
                i++;
            }
            else
                nuevoArreglo[i] = linesArray[i];
        }
        delete [] linesArray;
        linesArray = nuevoArreglo;

        /*for (int i = 0; i < sizeLine; i++) {
            linesArray[i] = nuevoArreglo[i];
        }*/

    }
    // Agregar el nuevo elemento al final del arreglo
   //linesArray[sizeLine-1] = elemento;
    else{
    for (int i = 0; i < sizeLine-1; i++) {
        if(TimeP==0){
            linesArray[i] = estaciones(NameSt, TimeP, TimeN);
        }
        else if(TimeN==0){
            linesArray[sizeLine-1] = estaciones(NameSt, TimeP, TimeN);
        }
        else if(linesArray[i].getNameStation()==NameSp){
            linesArray[i+1] = estaciones(NameSt, TimeP, TimeN);
            i++;
        }
        /*else
            linesArray[i] = linesArray[cont++];*/
        }
    }
}

string lineas::getLineName() const
{
    return lineName;
}

void lineas::operator=(const lineas &otraLinea)
{
    // Copiar los atributos
    lineName = otraLinea.lineName;
    sizeLine = otraLinea.sizeLine;
    capacidadLine = otraLinea.capacidadLine;

    // Copiar el arreglo dinámico de estaciones
    linesArray = new estaciones[capacidadLine];
    for (int i = 0; i < sizeLine; i++) {
        linesArray[i] = otraLinea.linesArray[i];
    }
}

/*void lineas::existe(string _lineName){

}*/

void lineas::mostrar()
{
    for(int i=0;i<sizeLine;i++){
        cout<<lineName<<" ";
        linesArray[i].mostrarSt();
        cout<<endl;
    }
}

void lineas::setSize(int _sizeLine)
{
    sizeLine=_sizeLine;
}

lineas::~lineas()
{
    delete[] linesArray;
}
