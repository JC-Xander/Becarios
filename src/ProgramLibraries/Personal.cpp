#include <Personal.h>

using namespace std;

Personal::Personal(int _idRol, int _idArea) {
    this->idRol = _idRol;
    this->idArea = _idArea;

    this->cordura = (rand() % 3) + 5;
} 

int Personal::getIdRol() { return this->idRol; }

string Personal::getRolAsignado() { return getRol(this->idRol); }

Tarea Personal::getTareaAsignada() { return this->tareaAsignada; }

void Personal::setAsignarTarea(Tarea _tarea) { this->tareaAsignada = _tarea; }
