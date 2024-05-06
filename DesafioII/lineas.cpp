#include "lineas.h"


lineas::lineas(string _lineName, int _sizeLine) {
    lineName = _lineName;
    sizeLine = _sizeLine;
    linesArray = new estaciones[sizeLine];
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

}

void lineas::addStation(lineas &line)
{
    string NameSt;
    int TimeP, TimeN;
    cout << "Ingrese el nombre de la estacion: "<<endl;
    cin.ignore();
    getline(cin,NameSt);
    cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina"<<endl;
    cout << "Ingrese el tiempo a la estacion siguiente: "<<endl;
    cin>>TimeN;
    cout << "Ingrese el tiempo a la estacion anterior: "<<endl;
    cin>>TimeP;

    if (sizeLine >= capacidadLine) {
        // Si el arreglo está lleno, aumentar su capacidad
        if (capacidadLine == 0) {
            capacidadLine = 1;
        }
        else {
            capacidadLine *= 2;
        }
        estaciones *nuevoArreglo = new estaciones[capacidadLine];
        // Copiar los elementos al nuevo arreglo
        for (int i = 0; i < sizeLine; i++) {
            nuevoArreglo[i] = linesArray[i];
        }

        // Liberar la memoria del arreglo anterior
        delete[] linesArray;
        linesArray = nuevoArreglo;
    }
    // Agregar el nuevo elemento al final del arreglo
   // linesArray[sizeLine++] = elemento; ESTO DEBE SER UN STRING CON EL NOMBRE

}

string lineas::getName() const
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
    linesArray = new estaciones[sizeLine];
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

bool lineas::getcompare(string _lineName){
        cout<<lineName<<endl;
        if (lineName==_lineName){
            cout<<lineName<<endl;
            return true;
        }
        else
            return false;
}

lineas::~lineas()
{
    delete[] linesArray;
}
