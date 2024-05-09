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
    int TimeP=0, TimeN, cont=0;

    for(int i=cont;i<sizeLine;i++){
        if (i!=0){
            TimeP = TimeN;}
        cout << "Ingrese el nombre de la estacion: "<<endl;
        cin.ignore();
        getline(cin,NameSt);

        /*for (int j=0; j<2; j++){

        }*/

        if(statBelongs(NameSt)==false){
            if (i<sizeLine-1){
                do{
                    cout << "Ingrese el tiempo a la estacion siguiente: ";
                    while (true){
                        cin >> TimeN;
                        if (cin.fail()){
                            cout<<"Valor invalido"<<endl;
                            cin.clear();
                            while (cin.get() != '\n') {
                                continue;}}
                        else
                            break;}
                } while(TimeN<0);}
            else
                TimeN=0;
            linesArray[i]=estaciones(NameSt, TimeP, TimeN);
            cout<<"Listo estacion creada"<<endl;
        }
        else{
            cout << "La estacion " << NameSt << " ya existe en esta linea" << endl;
            i--;
        }
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
    if (statBelongs(NameSt)==false){
        cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina"<<endl;
        do{
            cout << "Ingrese el tiempo a la estacion siguiente: "<<endl;
            while (true){
                cin >> TimeN;
                if (cin.fail()){
                    cout<<"Valor invalido"<<endl;
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        } while(TimeN<0);

        do{
             cout << "Ingrese el tiempo a la estacion anterior: "<<endl;
            while (true){
                cin >> TimeP;
                if (cin.fail()){
                    cout<<"Valor invalido"<<endl;
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        } while(TimeP<0);

        if (TimeN != 0 && TimeP != 0) {
            cout << "Ingrese el nombre de la estacion que se encontrara antes que la nueva estacion: "<<endl;
            cin.ignore();
            getline(cin, NameSp);
        }
        sizeLine++;
        if (sizeLine >= capacidadLine) {
            // Si el arreglo está lleno, aumentar su capacidad
            capacidadLine *= 2;
            estaciones *nuevoArreglo = new estaciones[capacidadLine];

            // Insertar la nueva estación al inicio del arreglo si TimeP es 0
            if (TimeP == 0) {
                nuevoArreglo[0] = estaciones(NameSt, TimeP, TimeN);

                for (int i = 0; i < sizeLine-1; i++) {
                    nuevoArreglo[i + 1] = linesArray[i];
                }
                nuevoArreglo[1].setTimePrev(TimeN);
            }
            // Insertar la nueva estación al final del arreglo si TimeN es 0
            else if (TimeN == 0) {
                for (int i = 0; i < sizeLine-1; i++) {
                    nuevoArreglo[i] = linesArray[i];
                }
                nuevoArreglo[sizeLine-1] = estaciones(NameSt, TimeP, TimeN);
                nuevoArreglo[sizeLine-2].setTimeNext(TimeP);
            } else {
                // Insertar la nueva estación después de NameSp
                int idx;
                for (idx = 0; idx < sizeLine-1; idx++) {
                    nuevoArreglo[idx] = linesArray[idx];
                    if (linesArray[idx].getNameStation() == NameSp) {
                        nuevoArreglo[idx + 1] = estaciones(NameSt, TimeP, TimeN);
                        nuevoArreglo[idx].setTimeNext(TimeP);
                        nuevoArreglo[idx + 2].setTimePrev(TimeN);
                        idx++; // Saltar la nueva estación que se ha insertado
                        break;
                    }
                }
                // Copiar las estaciones restantes
                for (; idx < sizeLine-1; idx++) {
                    nuevoArreglo[idx + 1] = linesArray[idx];
                }
            }

            delete[] linesArray;
            linesArray = nuevoArreglo;
        } else {
            // Si hay espacio en el arreglo, agregar la nueva estación al final
            if (TimeP == 0) {
                for (int i = sizeLine-1; i > 0; i--) {
                    linesArray[i] = linesArray[i - 1];
                }
                linesArray[0] = estaciones(NameSt, TimeP, TimeN);
                linesArray[1].setTimePrev(TimeN);
            } else if (TimeN == 0) {
                linesArray[sizeLine-1] = estaciones(NameSt, TimeP, TimeN);
                linesArray[sizeLine-2].setTimeNext(TimeP);
            } else {
                // Insertar la nueva estación después de NameSp
                int idx;
                for (idx = 0; idx < sizeLine-1; idx++) {
                    if (linesArray[idx].getNameStation() == NameSp) {
                        for (int j = sizeLine-1; j > idx; j--) {
                            linesArray[j] = linesArray[j - 1];
                        }
                        linesArray[idx + 1] = estaciones(NameSt, TimeP, TimeN);
                        linesArray[idx].setTimeNext(TimeP);

                        break;
                    }
                }
                linesArray[idx + 2].setTimePrev(TimeN);
                // Si no se encontró NameSp, insertar la nueva estación al final
                if (idx == sizeLine-1) {
                    linesArray[sizeLine-1] = estaciones(NameSt, TimeP, TimeN);
                }
            }
        }


    }
    else
        cout << "Ya existe una estacion con ese nombre" << endl;
}

void lineas::delStation(const string &nameStation) {
    for (int i = 0; i < sizeLine; i++) {
        if (linesArray[i].getNameStation() == nameStation && linesArray[i].getTransferencia()==false) {

            linesArray[i-1].setTimeNext(linesArray[i].getTimeNext() + linesArray[i].getTimePrev());
            linesArray[i+1].setTimePrev(linesArray[i].getTimeNext() + linesArray[i].getTimePrev());

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
    cerr << "La estación no se encontró en la línea."<<endl;
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

void lineas::compareStat(string NameSt)
{
    for(int i=0; i<sizeLine; i++){
        if(linesArray[i].getNameStation()==NameSt){
            linesArray[i].convertirTransferencia(lineName);
        }
    }
}

bool lineas::tieneTransf()
{
    for(int i=0; i<sizeLine; i++){
        if(linesArray[i].getTransferencia()==true){
            return true;
        }
    }
    return false;
}

lineas::~lineas()
{
    delete[] linesArray;
}
