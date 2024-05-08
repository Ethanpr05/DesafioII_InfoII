#include <iostream>
#include <string>
#include "redmetro.h"
#include "lineas.h"
#include "estaciones.h"

using namespace std;

int main()
{
    string lineName, nameStation;
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
            int sizeLine;
            cout<<"Ingrese el nombre de la linea: "<<endl;
            cin.ignore();
            getline(cin, lineName);
            cout << "Cuantas estaciones desea agregar inicialmente: "<<endl;
            cin>>sizeLine;
            cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina"<<endl;
            if(Red.lineaExist(lineName)==true){
                cout << "La linea " << lineName << " ya existe" <<endl;
            }
            else{
                Red.addLine(lineName, sizeLine);
                Red.showRed();
            }
        }
        break;

        case 2:{     
            cout << "A que linea se le agregara una estacion: "<<endl;
            cin.ignore();
            getline(cin, lineName);
            if(Red.lineaExist(lineName)==true){
                Red.lineFinder(lineName);
                Red.showRed();
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        case 3:{

            cout << "La red " << redName << " tiene " << Red.getCantLines() << " lineas." <<endl;
        }

        break;

        case 4:{
            cout << "Ingrese el nombre de la linea: "<<endl;
            cin.ignore();
            getline(cin, lineName);
            cout << lineName << endl;
            if(Red.lineaExist(lineName)==true){
            cout << "La linea " << lineName << " tiene " << Red.getLinea(lineName)->getSizeLine() << " estaciones" <<endl;
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        case 5:{
            cout << "Ingrese el nombre de la estacion: "<<endl;;
            cin.ignore();
            getline(cin, nameStation);
            cout << "Ingrese el nombre de la linea a la que pertenece la estacion: "<<endl;
            getline(cin, lineName);
            cout<<nameStation<<" "<<lineName<<endl;
            if(Red.lineaExist(lineName)==true){
                if(Red.getLinea(lineName)->statBelongs(nameStation)==true){
                    cout << "La estacion " << nameStation << " si pertenece a la linea " << lineName <<endl;
                }
                else
                    cout << "La estacion " << nameStation << " no pertenece a la linea " << lineName <<endl;
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        case 6:{
            cout << "A que linea pertenece la estacion que desea eliminar: ";
            cin.ignore();
            getline(cin, lineName);
            cout<<lineName<<endl;
            cout << "Ingrese el nombre de la estacion: "<<endl;
            getline(cin, nameStation);
            cout<<nameStation<<endl;
            if(Red.lineaExist(lineName)==true){
                Red.lineFinder(lineName, nameStation);
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        case 7:{
            cout << "Ingrese el nombre de la linea que desea eliminar: ";
            cin.ignore();
            getline(cin, lineName);
            cout<<lineName<<endl;
            if(Red.lineaExist(lineName)==true){
                if (Red.getLinea(lineName)->tieneTransf()==true){
                    cout << "La linea " << lineName << " no se puede eliminar ya que tiene una estacion de transferencia" <<endl;
                }
                else{
                    Red.delLine(lineName);
                    Red.showRed();}
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        case 8:{
            cout << "La red " << redName << " tiene " << Red.howManyStat() << " estaciones." <<endl;
        }
        break;

        case 9:{
            string nameStatOrig, nameStatDest;
            cout << "Ingrese el nombre de la estacion de origen: ";
            cin.ignore();
            getline(cin, nameStatOrig);
            cout << "Ingrese el nombre de la estacion de llegada: ";
            getline(cin, nameStatDest);
            cout << "Ingrese el nombre de la linea a la que pertenecen las estaciones: ";
            getline(cin, lineName);
            cout << "La linea es: " << lineName << endl;
            if(Red.lineaExist(lineName)==true){
                if(Red.getLinea(lineName)->statBelongs(nameStatDest)==true && Red.getLinea(lineName)->statBelongs(nameStatOrig)==true){
                    cout << "El tiempo que se tarda en llegar desde " << nameStatOrig << " a " << nameStatDest << " es: ";
                    Red.getLinea(lineName)->statFinder(nameStatOrig, nameStatDest);}
                else
                    cout << "Alguna de las estaciones ingresada no existe" << endl;
            }
            else{
                cout << "La linea no se encontro en la red de metro." << endl;
            }
        }
        break;

        }
    }
    return 0;
}
