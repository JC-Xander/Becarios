#include"Edificio.h"

using namespace std;

const string edificio[NUM_EDIFICIO] = {
    "B1",
    "B2",
    "D1",
    "E1",
    "K1"
};

const string area[NUM_AREA] = {
    "100",
    "200",
    "300",
    "Laboratorio",
    "Area de Estudio",
};

Edificio::Edificio() : edificioActual(-1){}

Edificio::Edificio(int _numEdificio) : edificioActual(_numEdificio) {
    for (int i = 0; i < NUM_AREA; i++){
        this->areaDisponible[i] = true;
    }
}

bool Edificio::asignarArea(int _numArea){
    if(_numArea >= NUM_AREA){
        cerr << "!ERROR¡ " <<"Area: " << _numArea << " No existe" << endl;
        exit(1);
    }
        

    if (this->areaDisponible[_numArea]){
        this->areaDisponible[_numArea] = false;
        this->totalAreasDisponibles--;
        return true;
    }

    return false;
}

int Edificio::buscarAsignarArea(){
    if (!this->totalAreasDisponibles){
        return -1;
    }

    for (int i = 0; i < NUM_AREA; i++){
        if (areaDisponible[i]){
            this->asignarArea(i);
            return i;
        }
    }

    return -1;
}

bool Edificio::desocuparArea(int _numArea){
    if(_numArea >= NUM_AREA){
        cerr << "!ERROR¡ " <<"Area: " << _numArea << " No existe" << endl;
        exit(1);
    }

    if (this->areaDisponible[_numArea]){
        return false;
    }else{
        this->areaDisponible[_numArea] = true;
        this->totalAreasDisponibles++;
        return true;
    }
}

int Edificio::getIdEdificio(){
    return this->edificioActual;
}

int Edificio::getTotalAreasDisponibles(){
    return this->totalAreasDisponibles;
}
string Edificio::getEdificio(){
    return edificio[this->edificioActual];
}
string Edificio::getArea(int _numArea){
    return area[_numArea];
}

string Edificio::getData(int _numArea){
    string auxEdificio = this->getEdificio();
    string auxArea = this->getArea(_numArea);
    return auxEdificio + " : " + auxArea;
}

