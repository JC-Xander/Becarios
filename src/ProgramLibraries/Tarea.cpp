#include "Tarea.h"

using namespace std;

const int MAX_DIFICULTAD = 5;

vector<string> sofware = {
    "sofware tares 0",
    "sofware tares 1",
    "sofware tares 2",
    "sofware tares 3",
    "sofware tares 4"
};

vector<string> hardware = {
    "hardware tares 0",
    "hardware tares 1",
    "hardware tares 2",
    "hardware tares 3",
    "hardware tares 4"
};

vector<string> datos = {
    "datos tares 0",
    "datos tares 1",
    "datos tares 2",
    "datos tares 3",
    "datos tares 4"
};

vector<string> redes = {
    "redes tares 0",
    "redes tares 1",
    "redes tares 2",
    "redes tares 3",
    "redes tares 4"
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