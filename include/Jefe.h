#ifndef JEFE_H
#define JEFE_H

#include <iostream>
#include <vector> 

#include "Entorpecedor.h"
#include "Edificio.h"
#include "Tarea.h"

class Jefe {
private:
    int idJefe;
    Edificio edificio;
    Entorpecedor entorpecedor;
    int numGrupo; 
    int contTareasCompletadas;
    int contTareasAbandonadas;

    

public:
    Jefe(int);
    /**
     * Genera una instancia de jefe con un ID
     */
    Jefe(const int, int);

    Edificio getEdificio();

    int getIdJefe();
    int getContTareasCompletados();
    int getContTareasAbandonadas();

    /**
     * Agrega personal al grupo
     * @return retorna verdadero si añade el personal de lo contrario retorna falso
     */
    bool AgregarPersonal();

    /**
     * Retorna el nuemro de integrantes del grupo
     */
    int getNumGrupo();

    Tarea PedirTarea(int);

    bool Ayuda();

    bool pedirDocumentacion();

};

#endif // JEFE_H
