#include "Jefe.h"

using namespace std;

// Constructor
Jefe::Jefe(int _ID) : idJefe(_ID) {}

Jefe::Jefe(const int _ID, int _idEdificio) {
    this->idJefe = _ID;
    Edificio edificioAux(_idEdificio);
    this->edificio = edificioAux;

    Entorpecedor entorpecedorAux(_idEdificio);
    this->entorpecedor = entorpecedorAux;

    this->numGrupo = 10;
    this->contTareasCompletadas = 5;
    this->contTareasAbandonadas = 5;
}

int Jefe::getIdJefe() { return this->idJefe; }

Edificio Jefe::getEdificio() { return this->edificio; }

int Jefe::getContTareasCompletados() { return this->contTareasCompletadas; }

int Jefe::getContTareasAbandonadas() { return this->contTareasAbandonadas; }

int Jefe::getNumGrupo(){
    return this->numGrupo;
}

bool Jefe::AgregarPersonal() {
    return true;
}
Tarea Jefe::PedirTarea(int _idRol){
    Tarea tareaAux(-1, -1);
    return tareaAux;
}
bool Jefe::Ayuda(){
    return false;
}
bool Jefe::pedirDocumentacion(){
    return false;
}