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
            cin.ignore();
            getline(cin, whichLine);
            cout << whichLine << endl;
            if(Red.lineaExist(whichLine)==true){
            cout << "La linea " << whichLine << " tiene " << Red.getLinea(whichLine)->getSizeLine() << " estaciones" <<endl;
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        case 5:{
            string whichLine, nameStat;
            cout << "Ingrese el nombre de la estacion: "<<endl;;
            cin.ignore();
            getline(cin, nameStat);
            cout << "Ingrese el nombre de la linea a la que pertenece la estacion: "<<endl;
            getline(cin, whichLine);
            cout<<nameStat<<" "<<whichLine<<endl;
            if(Red.getLinea(whichLine)->statBelongs(nameStat)==true){
                cout << "La estacion " << nameStat << " si pertenece a la linea " << whichLine <<endl;
            }
            else
                cout << "La estacion " << nameStat << " no pertenece a la linea " << whichLine <<endl;
        }
        break;

        case 6:{
            string lineName, nameStation;
            cout << "A que linea pertenece la estacion que desea eliminar: ";
            cin.ignore();
            getline(cin, lineName);
            cout<<lineName<<endl;
            cout << "Ingrese el nombre de la estacion: "<<endl;
            //cin.ignore();
            getline(cin, nameStation);
            cout<<nameStation<<endl;
            Red.lineFinder(lineName, nameStation);
        }
        break;

        case 7:{
            string lineName;
            cout << "Ingrese el nombre de la linea que desea eliminar: ";
            cin.ignore();
            getline(cin, lineName);
            cout<<lineName<<endl;
            Red.delLine(lineName);
            Red.showRed();
        }
        break;

        case 8:{
            cout << "La red " << redName << " tiene " << Red.howManyStat() << " estaciones." <<endl;
        }
        break;

        case 9:{
            string nameStatOrig, nameStatDest, whichLine;
            cout << "Ingrese el nombre de la estacion de origen: ";
            cin.ignore();
            getline(cin, nameStatOrig);
            cout << "Ingrese el nombre de la estacion de llegada: ";
            getline(cin, nameStatDest);
            cout << "Ingrese el nombre de la linea a la que pertenecen las estaciones: ";
            getline(cin, whichLine);
            cout << "La linea es: " << whichLine << endl;
            cout << "El tiempo que se tarda en llegar desde " << nameStatOrig << " a " << nameStatDest << " es: ";
            Red.getLinea(whichLine)->statFinder(nameStatOrig, nameStatDest);
        }
        break;

        }
    }
    return 0;
}
