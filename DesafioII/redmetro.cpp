#include "redmetro.h"


redMetro::redMetro(string _redName, int _sizeRed)
{
    redName = _redName;
    sizeRed = _sizeRed;
    capacidadRed = 2;
    while(sizeRed>=capacidadRed){
        capacidadRed *= 2;
    }
    redsArray = new lineas[capacidadRed];
    cin.ignore();
    for (int i=0;i<sizeRed;i++){
        string lineName;
        int sizeLine;
        cout<<"Ingrese el nombre de la linea: "<<endl;
        getline(cin, lineName);
        do{
            cout << "Cuantas estaciones desea agregar inicialmente: "<<endl;
            while (true){
                cin >> sizeLine;
                if (cin.fail()){
                    cout<<"Valor invalido"<<endl;
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        } while(sizeLine<0);
        if (lineaExist(lineName)==false){
            redsArray[i]=lineas (lineName, sizeLine);
            cout<<"Listo"<<endl;}
        else{
            cout << "La linea " << lineName << " ya existe." <<endl;
            i--;
        }


    if (i>0){
        string NameSt;
        cout << "Ingrese el nombre de la estacion de transferencia" << endl;
        getline(cin,NameSt);
        cout << "Nombre " << NameSt << endl;
        for (int j=0;j<=i;j++){
        redsArray[j].compareStat(NameSt);}
    }

    }
}

void redMetro::showRed()
{
    cout << redName << endl;
    for (int i=0;i<sizeRed;i++){
        redsArray[i].mostrar();
    }
}

void redMetro::addLine(string lineName, int sizeLine)
{
    sizeRed++;
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
        for (int i = 0; i < sizeRed-1; i++) {
            nuevoArreglo[i] = redsArray[i];
        }
        delete[] redsArray;
        redsArray = nuevoArreglo;

       /* for (int i = 0; i < sizeRed; i++) {
            redsArray[i] = nuevoArreglo[i];
        }*/
        //delete[] nuevoArreglo;
        //nuevoArreglo=nullptr;
    }
    // Agregar el nuevo elemento al final del arreglo
    redsArray[sizeRed-1] = lineas(lineName, sizeLine);

        string NameSt;
        cout << "Ingrese el nombre de la estacion de transferencia" << endl;
        getline(cin,NameSt);
        cout << "Nombre " << NameSt << endl;
        for (int j=0;j<sizeRed;j++){
            redsArray[j].compareStat(NameSt);}
}

void redMetro::lineFinder(string _lineName)const {

    for (int i=0;i<sizeRed;i++){
        if(redsArray[i].getLineName() == _lineName){
            redsArray[i].addStation();
            break;}
    }
}

void redMetro::lineFinder(string &_lineName, string &_nameStation)const {

    for (int i=0;i<sizeRed;i++){
        if(redsArray[i].getLineName() == _lineName){
            if(redsArray[i].statBelongs(_nameStation)==true){
                redsArray[i].delStation(_nameStation);}
            else
                cout << "La estacion no se encontro en la linea" << endl;
            break;}
    }
}

int redMetro::getCantLines() const{
    return sizeRed;
}

int redMetro::howManyStat() const
{
    // Método para contar cuántas estaciones tiene la red de metro
        int totalEstaciones = 0;
        for (int i = 0; i < sizeRed; ++i) {
            totalEstaciones += redsArray[i].getSizeLine();
        }
        return totalEstaciones;
}

lineas* redMetro::getLinea(string &_lineName) const{
    for (int i=0;i<sizeRed;i++){
        if(redsArray[i].getLineName()==_lineName){
            return &redsArray[i];
            break;}
    }
}

void redMetro::delLine(const string _lineName)
{
    // Método para eliminar una línea del arreglo
        for (int i = 0; i < sizeRed; i++) {
            if (redsArray[i].getLineName() == _lineName) {
                // Eliminar la línea encontrada del arreglo
                for (int j = i; j < sizeRed - 1; j++) {
                    redsArray[j] = redsArray[j + 1];
                }
                --sizeRed;

                // Verificar si el tamaño del arreglo es divisible por un múltiplo de 2^n
                if (sizeRed > 0 && (sizeRed & (sizeRed - 1)) == 0) {
                    // Si el tamaño del arreglo es divisible por un múltiplo de 2^n,
                    // reducir su capacidad a la mitad
                    capacidadRed /= 2;
                    lineas* nuevoArreglo = new lineas[capacidadRed];
                    for (int k = 0; k < sizeRed; k++) {
                        nuevoArreglo[k] = redsArray[k];
                    }
                    delete[] redsArray;
                    redsArray = nuevoArreglo;
                }

                // Salir del bucle una vez que se haya eliminado la línea
                return;
            }
        }
    // Si no se encuentra la línea, puedes manejar el error adecuadamente aquí
        cerr << "La linea no se encontro en el arreglo."<<endl;
}

bool redMetro::lineaExist(string &lineName)
{
    for (int i=0;i<sizeRed;i++){
        if(redsArray[i].getLineName()==lineName){
            return true;
            break;}
    }
    return false;
}



redMetro::~redMetro()
{
    delete[]redsArray;
}
