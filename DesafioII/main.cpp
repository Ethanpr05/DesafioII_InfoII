#include <iostream>

using namespace std;

int main()
{
    int opcion=1;
    cout<<"---------- Informa2 seguridad ----------"<<endl;
    while(opcion!=0)
    {
        cout<<"1.Agregar una estacion a una linea"<<endl;
        cout<<"2.Eliminar una estacion de una linea"<<endl;
        cout<<"3.Cantidad de lineas que tiene la red Metro"<<endl;
        cout<<"4.Cantidad de estaciones en una linea dada"<<endl;
        cout<<"5.Saber si una estacion pertenece a una linea"<<endl;
        cout<<"6.Agregar una linea a la red Metro"<<endl;
        cout<<"7.Eliminar una linea de la red Metro"<<endl;
        cout<<"8.Cantidad de estaciones que tiene una red Metro"<<endl;
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
        } while(opcion<0 || opcion>8);

        switch(opcion){

        case 1:{
            cout << "A que linea se le agregara una estacion: ";

            cout << "Cuantas estaciones desea agregar: ";

            cout << "Si el tiempo a la estacion anterior o siguiente es 0, la estacion se crea en una esquina";

            for(){
                cout << "Ingrese el nombre de la estacion: ";

                cout << "Ingrese el tiempo a la estacion siguiente: ";

                cout << "Ingrese el tiempo a la estacion anterior: ";
            }
        }
        break;

        case 2:{
            cout << "A que linea pertenece la estacion que desea eliminar: ";

            cout << "Ingrese el nombre de la estacion: ";

        }
        break;

        case 3:{

        }
        break;

        case 4:{
            cout << "Ingrese el nombre de la linea: ";

        }
        break;

        case 5:{
            cout << "Ingrese el nombre de la estacion: ";

            cout << "Ingrese el nombre de la linea: ";
        }
        break;

        case 6:{
            cout << "Ingrese el nombre de la linea que desea agregar: ";

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
