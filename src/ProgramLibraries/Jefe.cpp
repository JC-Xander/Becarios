#include "Jefe.h"

// Constructor
Jefe::Jefe(const int _ID) : Becario(_ID), numGrupo(0) {}

bool Jefe::AgregarPersonal() {
    
    return true;
}

// Obtiene el puntero al grupo de becarios
std::vector<Becario> Jefe::getGrupo() const {
    return this->Grupo;
}

// Obtiene el numero de integrantes del grupo
int Jefe::getNumGrupo() const {
    return this->numGrupo;
}

std::ostream& operator<<(std::ostream& os, const Becario& _jefe){
    os << _jefe.getID() << " ) ";
}