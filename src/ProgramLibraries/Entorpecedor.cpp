#include "Entorpecedor.h"

using namespace std;

Entorpecedor:: Entorpecedor() : edificio(-1) {}

Entorpecedor::Entorpecedor(const int _idEdificio) : edificio(_idEdificio) {}

bool Entorpecedor::setIdBecario(const int _idBecario){
    this->idBecario = _idBecario;
    return true;
}

bool Entorpecedor::MolestarBecario(){
    if (idBecario == -1)
        return false;

    int accionAleatoria = rand() % NUM_ACCIONES;
    cout << "El entorpecedor del "<< this->edificio << " molesta al becario " << idBecario << endl;
    cout << this->acciones[accionAleatoria] << endl;
    sleep(1);
    return true;
}

bool Entorpecedor::FinalizoTarea(){
    this->idBecario = -1;
    return true;
}