#include <iostream>
#include <string>
#include "redmetro.h"
#include "lineas.h"
#include "estaciones.h"

using namespace std;

int main()
{
    int opcion=1;
    cout<<"---------- Metro Red simulator prototype ----------"<<endl;
    cout<<"Creacion red metro"<<endl;
    string redName;
    int howManyLines;
    cout << "Ingrese el nombre de la red metro: "<<endl;
    //cin.ignore();
    getline(cin, redName);
    cout << "Ingrese el numero de lineas que tendra inicialmente la red metro: "<<endl;
    cin>>howManyLines;
    redMetro Red(redName, howManyLines);
    Red.showRed();

    //  red.addLine(line);

    while(opcion!=0)
    {
        cout<<"1.Agregar una linea a la red Metro"<<endl;
        cout<<"2.Agregar una estacion a una linea"<<endl;
        cout<<"3.Cantidad de lineas que tiene la red Metro"<<endl;
        cout<<"4.Cantidad de estaciones en una linea dada"<<endl;
        cout<<"5.Saber si una estacion pertenece a una linea"<<endl;
        cout<<"6.Eliminar una estacion de una linea"<<endl;
        cout<<"7.Eliminar una linea de la red Metro"<<endl;
        cout<<"8.Cantidad de estaciones que tiene la red Metro"<<endl;
        cout<<"9.Calcular el tiempo de llegada entre estaciones"<<endl;
        cout<<"0.Para salir del menu"<<endl;

        do{
            cout<<"Escriba el numero de la opcion querida para elegirla"<<endl;
            while (true){
                cin >> opcion;
                if (cin.fail()){
                    cout<<"Valor invalido"<<endl;
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        } while(opcion<0 || opcion>9);

        switch(opcion){

        case 1:{
            string lineName;
            int sizeLine;
            cout<<"Ingrese el nombre de la linea: "<<endl;
            cin.ignore();
            getline(cin, lineName);
            cout << "Cuantas estaciones desea agregar inicialmente: "<<endl;
            cin>>sizeLine;
            cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina"<<endl;

            Red.addLine(lineName, sizeLine);
            Red.showRed();

        }
        break;

        case 2:{     
            string whichLine;
            cout << "A que linea se le agregara una estacion: "<<endl;
            cin.ignore();
            getline(cin, whichLine);
            Red.lineFinder(whichLine);
            Red.showRed();
        }
        break;

        case 3:{

            cout << "La red " << redName << " tiene " << Red.getCantLines() << " lineas." <<endl;

        }

        break;

        case 4:{
            string whichLine;
            cout << "Ingrese el nombre de la linea: "<<endl;
            getline(cin, whichLine);
            cin.ignore();
            cout << "La linea " << whichLine << " tiene " << Red.getLinea(whichLine).howManyStat() << " estaciones" <<endl;
        }
        break;

        case 5:{
            string whichLine, nameStat;
            cout << "Ingrese el nombre de la estacion: ";
            getline(cin, nameStat);
            cin.ignore();
            cout << "Ingrese el nombre de la linea a la que pertenece la estacion: ";
            getline(cin, whichLine);
            cin.ignore();
            if(Red.getLinea(whichLine).statBelongs(nameStat)==true){
                cout << "La estacion " << nameStat << " si pertenece a la linea " << whichLine <<endl;
            }
            else
                cout << "La estacion " << nameStat << " no pertenece a la linea " << whichLine <<endl;
        }
        break;

        case 6:{

            cout << "A que linea pertenece la estacion que desea eliminar: ";

            cout << "Ingrese el nombre de la estacion: ";


        }
        break;

        case 7:{
            cout << "Ingrese el nombre de la linea que desea eliminar: ";

        }
        break;

        case 8:{

        }
        break;

        }
    }
    return 0;
}
