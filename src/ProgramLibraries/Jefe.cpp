#include "Jefe.h"

using namespace std;

string Jefe::circunstancias[CIRCUNSTANCIAS_JEFE] = {
    "no estaba en su area de trabajo",
    "estaba comiendo"
};

// -- CONSTRUCTORES --
Jefe::Jefe(int _ID) : idJefe(_ID) {}

Jefe::Jefe(const int _ID, int _idEdificio) {
    this->idJefe = _ID;
    Edificio edificioAux(_idEdificio);
    this->edificio = edificioAux;

    Entorpecedor entorpecedorAux(_idEdificio);
    this->entorpecedor = entorpecedorAux;

    this->contPersonal = 0;
    this->contTareasCompletadas = 0;
    this->contTareasAbandonadas = 0;
    this->contTareasParcheadas = 0;
    this->jornada = JORNADA;
}


// -- GETTERS
int Jefe::getIdJefe() { return this->idJefe; }

Edificio Jefe::getEdificio() { return this->edificio; }

int Jefe::getContTareasCompletados() { return this->contTareasCompletadas; }

int Jefe::getContTareasAbandonadas() { return this->contTareasAbandonadas; }

int Jefe::getContPersonal() { return this->contPersonal; }

// -- METODOS --
void Jefe::tareaCompletada() { this->contTareasCompletadas++; }

void Jefe::tareaAbandonada() { this->contTareasAbandonadas++; }

void Jefe::tareaParcheada() { this->contTareasParcheadas++; }

bool Jefe::AgregarPersonal() {
    if ((rand() % 5) != 0){
        this->contPersonal++;
        return true;
    }

    return false;
}

bool Jefe::PedirTarea(Personal _personal){
    if (jornada <= INIT_PARCHEOS){
        return false;
    }

    int _rol = _personal.getIdRol();
    Tarea _tarea(_rol);
    _personal.setAsignarTarea(_tarea);
    return true;
}

bool Jefe::Ayuda(){ 
    if ((rand() % 10) != 0){
        sleep(2);
        return true;
    }else{
        return false;
    }
 }

bool Jefe::pedirDocumentacion(){
    sleep(1);
    return ((rand() % 10) == 0) ? false : true;
}