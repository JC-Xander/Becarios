#include "Jefe.h"

using namespace std;

string Jefe::circunsta[NUM_CIRCUNSTANCIAS] = {
    "no estaba en su area de trabajo.",
    "estaba comiendo."
};

// -- CONSTRUCTORES --
Jefe::Jefe(int _ID) : idJefe(_ID) {}

Jefe::Jefe(const int _ID, int _idEdificio) {
    this->idJefe = _ID;
    Edificio edificioAux(_idEdificio);
    this->edificio = edificioAux;

    Entorpecedor entorpecedorAux(_idEdificio);
    this->entorpecedor = entorpecedorAux;

    this->numGrupo = 0;
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

int Jefe::getNumGrupo() { return this->numGrupo; }

// -- METODOS --
void Jefe::tareaCompletada() { this->contTareasCompletadas++; }

void Jefe::tareaAbandonada() { this->contTareasAbandonadas++; }

void Jefe::tareaParcheada() { this->contTareasParcheadas++; }

int AgregarPersonal(int _idPersonal, int _idArea) {

    return true;
}
bool Jefe::PedirTarea(Personal _personal){
    if (jornada == 0){
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