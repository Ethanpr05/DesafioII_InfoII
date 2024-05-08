#include "lineas.h"


lineas::lineas(string _lineName, int _sizeLine) {
    lineName = _lineName;
    sizeLine = _sizeLine;
    capacidadLine = 2;
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

void lineas::addStation() {
    string NameSt, NameSp;
    int TimeP, TimeN;

    cout << "Ingrese el nombre de la estacion: ";
    getline(cin, NameSt);

    cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina\n";
    cout << "Ingrese el tiempo a la estacion siguiente: ";
    cin >> TimeN;
    cout << "Ingrese el tiempo a la estacion anterior: ";
    cin >> TimeP;

    if (TimeN != 0 && TimeP != 0) {
        cout << "Ingrese el nombre de la estacion que se encontrara antes que la nueva estacion: ";
        cin.ignore();
        getline(cin, NameSp);
    }

    if (sizeLine >= capacidadLine) {
        // Si el arreglo está lleno, aumentar su capacidad
        capacidadLine *= 2;
        estaciones *nuevoArreglo = new estaciones[capacidadLine];

        // Insertar la nueva estación al inicio del arreglo si TimeP es 0
        if (TimeP == 0) {
            nuevoArreglo[0] = estaciones(NameSt, TimeP, TimeN);
            for (int i = 0; i < sizeLine; i++) {
                nuevoArreglo[i + 1] = linesArray[i];
            }
        }
        // Insertar la nueva estación al final del arreglo si TimeN es 0
        else if (TimeN == 0) {
            for (int i = 0; i < sizeLine; i++) {
                nuevoArreglo[i] = linesArray[i];
            }
            nuevoArreglo[sizeLine] = estaciones(NameSt, TimeP, TimeN);
        } else {
            // Insertar la nueva estación después de NameSp
            int idx;
            for (idx = 0; idx < sizeLine; idx++) {
                nuevoArreglo[idx] = linesArray[idx];
                if (linesArray[idx].getNameStation() == NameSp) {
                    nuevoArreglo[idx + 1] = estaciones(NameSt, TimeP, TimeN);
                    idx++; // Saltar la nueva estación que se ha insertado
                    break;
                }
            }
            // Copiar las estaciones restantes
            for (; idx < sizeLine; idx++) {
                nuevoArreglo[idx + 1] = linesArray[idx];
            }
        }

        delete[] linesArray;
        linesArray = nuevoArreglo;
    } else {
        // Si hay espacio en el arreglo, agregar la nueva estación al final
        if (TimeP == 0) {
            for (int i = sizeLine; i > 0; i++) {
                linesArray[i] = linesArray[i - 1];
            }
            linesArray[0] = estaciones(NameSt, TimeP, TimeN);
        } else if (TimeN == 0) {
            linesArray[sizeLine] = estaciones(NameSt, TimeP, TimeN);
        } else {
            // Insertar la nueva estación después de NameSp
            int idx;
            for (idx = 0; idx < sizeLine; ++idx) {
                if (linesArray[idx].getNameStation() == NameSp) {
                    for (int j = sizeLine; j > idx; j--) {
                        linesArray[j] = linesArray[j - 1];
                    }
                    linesArray[idx + 1] = estaciones(NameSt, TimeP, TimeN);
                    break;
                }
            }
            // Si no se encontró NameSp, insertar la nueva estación al final
            if (idx == sizeLine) {
                linesArray[sizeLine] = estaciones(NameSt, TimeP, TimeN);
            }
        }
    }

    sizeLine++; // Incrementar el tamaño del arreglo
}

void lineas::delStation(const string &nameStation) {
    for (int i = 0; i < sizeLine; i++) {
        if (linesArray[i].getNameStation() == nameStation) {
            // Eliminar la estación encontrada del arreglo
            for (int j = i; j < sizeLine - 1; j++) {
                linesArray[j] = linesArray[j + 1];
            }
            sizeLine--;

            // Verificar si el tamaño del arreglo es divisible por un múltiplo de 2^n
            if (sizeLine > 0 && (sizeLine & (sizeLine - 1)) == 0) {
                // Si el tamaño del arreglo es divisible por un múltiplo de 2^n,
                // reducir su capacidad a la mitad
                capacidadLine /= 2;
                estaciones* nuevoArreglo = new estaciones[capacidadLine];
                for (int k = 0; k < sizeLine; k++) {
                    nuevoArreglo[k] = linesArray[k];
                }
                delete[] linesArray;
                linesArray = nuevoArreglo;
            }

            // Salir del bucle una vez que se haya eliminado la estación
            return;
        }
    }
    // Si no se encuentra la estación, puedes manejar el error adecuadamente aquí
    cerr << "La estación no se encontró en la línea.\n";
}

int lineas::getSizeLine()
{
    return sizeLine;
}

string lineas::getLineName() const
{
    return lineName;
}

bool lineas::statBelongs(string nameStat)
{
    for(int i=0; i<sizeLine; i++){
        if(linesArray[i].getNameStation()==nameStat){
            return true;
        }
    }
    return false;
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

void lineas::statFinder(string nameStatOrig, string nameStatprev)
{
    int calcTime = 0;
    for(int i=0; i<sizeLine; i++){
        if(linesArray[i].getNameStation()==nameStatOrig){
            for(int j=0; j<sizeLine; j++){
                if(linesArray[j].getNameStation()==nameStatprev){
                    if(i>j){
                        for(int a = j; a<i;a++){
                            calcTime = linesArray[a].calcTiempo(calcTime);}
                        }
                    else{
                        for(int b = i; b<j;b++){
                            calcTime = linesArray[b].calcTiempo(calcTime);}
                    }
                        cout << calcTime << endl;
                }
            }
        }
    }
}

lineas::~lineas()
{
    delete[] linesArray;
}
