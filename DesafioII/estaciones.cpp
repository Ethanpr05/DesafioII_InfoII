#include "estaciones.h"

estaciones::estaciones()
{
    nameStation = "";
    timePrev = 0;
    timeNext = 0;
}

estaciones::estaciones(string _nameStation, int _timePrev, int _timeNext) {

    this->nameStation= _nameStation;
    this->timePrev=_timePrev;
    this->timeNext=_timeNext;
}

void estaciones::operator=(const estaciones &otraEstacion)
{
    nameStation = otraEstacion.nameStation;
    timePrev = otraEstacion.timePrev;
    timeNext = otraEstacion.timeNext;
}

/*estaciones(string _nameStation, int _timePrev){
    this->nameStation=_nameStation;
    this->timePrev=_timePrev;
}

estaciones(string _nameStation, int _timeNext){
    this->nameStation=_nameStation;
    this->timeNext=_timeNext;
}*/

void estaciones::setnameStation(string _nameStation){
    nameStation=_nameStation;
}

string estaciones::getNameStation() const{
    return nameStation;
}

void estaciones::setTimePrev(int _timePrev){
    timePrev=_timePrev;
}

int estaciones::getTimePrev() const{
    return timePrev;
}

void estaciones::mostrarSt()
{
    cout<<"Nombre St: "<<nameStation<<" TP: "<<timePrev<<" TN: "<<timeNext<<endl;

}

void estaciones::setTimeNext(int _timeNext){
    timeNext=_timeNext;
}

int estaciones::getTimeNext() const{
    return timeNext;
}


estaciones::~estaciones()
{

}

/*void estaciones::setDeleteStation(string _nameStation){

}*/


