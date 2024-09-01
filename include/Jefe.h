#ifndef JEFE_H
#define JEFE_H

#include <iostream>
#include <vector> 
#include "Becario.h"
#include "Entorpecedor.h"

class Jefe : public Becario {
private:
    int Edificio;
    int numGrupo; 
    Entorpecedor entorpecedor;
    

public:
    /**
     * Genera una instancia de jefe con un ID
     */
    Jefe(const int, int);

    /**
     * Agrega personal al grupo
     * @return retorna verdadero si añade el personal de lo contrario retorna falso
     */
    bool AgregarPersonal();

    /**
     * Retorna el nuemro de integrantes del grupo
     */
    int getNumGrupo() const;

    bool PedirTarea();

    bool Ayuda();

    bool pedirDocumentacion();

};

#endif // JEFE_H
