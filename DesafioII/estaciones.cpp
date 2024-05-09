#include "estaciones.h"

estaciones::estaciones()
{
    nameStation = "";
    timePrev = 0;
    timeNext = 0;
    transferencia = false;
}

estaciones::estaciones(string _nameStation, int _timePrev, int _timeNext) {

    this->nameStation= _nameStation;
    this->timePrev=_timePrev;
    this->timeNext=_timeNext;
    transferencia = false;
}

void estaciones::operator=(const estaciones &otraEstacion)
{
    nameStation = otraEstacion.nameStation;
    timePrev = otraEstacion.timePrev;
    timeNext = otraEstacion.timeNext;
    transferencia = otraEstacion.transferencia;
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

int estaciones::calcTiempo(int calcTime) const{
    int timenext = getTimeNext();
    //int timeprev = getTimePrev();
    calcTime+=timenext;

    return calcTime;
}

void estaciones::convertirTransferencia(string lineName)
{
    transferencia=true;
    nameStation+= " " + lineName;
}

bool estaciones::getTransferencia()
{
    return transferencia;
}


estaciones::~estaciones()
{

}

/*void estaciones::setDeleteStation(string _nameStation){

}*/


