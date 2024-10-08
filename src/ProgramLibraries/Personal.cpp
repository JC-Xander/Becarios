#include <Personal.h>

using namespace std;

string Personal::circunstacias[CIRCUNSTANCIAS_PERSONAL] = {
    "se enfermo.",
    "tuvo un accidente",
    "tuvo dia libre"
};

Personal::Personal(int _idRol, int _idArea) {
    this->idRol = _idRol;
    this->idArea = _idArea;

    this->cordura = (rand() % 3) + 5;
} 

int Personal::getIdRol() { return this->idRol; }

string Personal::getRolAsignado() { return getRol(this->idRol); }

Tarea Personal::getTareaAsignada() { return this->tareaAsignada; }

void Personal::setAsignarTarea(Tarea _tarea) { this->tareaAsignada = _tarea; }

bool Personal::disminuirCordura() {
    this->cordura--;

    if(this->cordura == 0){
        this->cordura = (rand() % 3) + 5;
        return true;
    }

    return false;
}
