#include "Tarea.h"

using namespace std;

Tarea::Tarea(int _idTarea, int _dificultad){
    this->idTarea = _idTarea;
    this->dificultad = _dificultad;

    int _electrica = rand() % 2;
    if(_electrica)
        this->esElectrica = true;
    else
        this->esElectrica = false;
}

int Tarea::getIdTarea() const { return this->idTarea; }

int Tarea::getDificultad() const { return this->dificultad; }

bool Tarea::getDocumentacion(){
    int num = rand() % 4;
    if( num == 0)
        return false;
    else
        return true;
}