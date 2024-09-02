#include "Entorpecedor.h"


using namespace std;

Entorpecedor:: Entorpecedor() : idEdificio(-1) {}

Entorpecedor::Entorpecedor(const int _idEdificio) : idEdificio(_idEdificio), idBecario(-1) {}

int Entorpecedor::getIdBecario() { return this->idBecario; }

bool Entorpecedor::setIdBecario(const int _idBecario){
    this->idBecario = _idBecario;
    return true;
}

bool Entorpecedor::molestarBecario(){
    if (this->idBecario == -1)
        return false;

    int accionAleatoria = rand() % NUM_ACCIONES;
    cout << "El entorpecedor del "<< Edificio::getNombreEdificio(this->idEdificio) << " molesta al becario " << idBecario << endl;
    cout << this->acciones[accionAleatoria] << endl;
    sleep(1);
    return true;
}

bool Entorpecedor::FinalizoTarea(){
    this->idBecario = -1;
    return true;
}