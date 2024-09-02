#include "Tarea.h"

using namespace std;

vector<string> sofware = {
    "sofware tarea 0",
    "sofware tarea 1",
    "sofware tarea 2",
    "sofware tarea 3",
    "sofware tarea 4"
};

vector<string> hardware = {
    "hardware tarea 0",
    "hardware tarea 1",
    "hardware tarea 2",
    "hardware tarea 3",
    "hardware tarea 4"
};

vector<string> datos = {
    "datos tarea 0",
    "datos tarea 1",
    "datos tarea 2",
    "datos tarea 3",
    "datos tarea 4"
};

vector<string> redes = {
    "redes tarea 0",
    "redes tarea 1",
    "redes tarea 2",
    "redes tarea 3",
    "redes tarea 4"
};

vector<vector<string>> TotalTareas = {
    sofware,
    hardware,
    datos,
    redes
};

Tarea::Tarea() {};

Tarea::Tarea(int _idRol){
    this->idRol = _idRol;

    int numTarea = TotalTareas[idRol].size();
    this->idTarea = rand() % numTarea;

    this->dificultad = ((rand() % MAX_DIFICULTAD) + 1);

    ((rand() % 4) != 0) ? this->esElectrica = true : this->esElectrica = false;
}

string Tarea::getNombreTarea() const { return TotalTareas[this->idRol][this->idTarea]; }

int Tarea::getDificultad() const { return this->dificultad; }

bool Tarea::getDocumentacion() { return ((rand() % 4) != 0) ? true : false; }