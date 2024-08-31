#include "Tarea.h"
#include <iostream>
using namespace std;

Tarea::Tarea(string _nombre, int _dificultad, bool _esElectrica){
    this->nombre = _nombre;
    this->dificultad = _dificultad;
    this->esElectrica = _esElectrica;
}

string Tarea::getNombre() const { return this->nombre; }

int Tarea::getDificultad() const { return this->dificultad; }

bool Tarea::getDocumentacion(){
    int num = 0 + rand() % 3;
    if( num == 0)
        return false;
    else
        return true;
}

ostream& operator<<(ostream& os, const Tarea& _tarea){
    os << _tarea.getNombre();
    return os;
}