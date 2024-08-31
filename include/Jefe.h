#ifndef JEFE_H
#define JEFE_H

#include "Becario.h"
#include <iostream>
#include <vector> 

class Jefe : public Becario {
private:
    std::vector<Becario> Grupo;
    int numGrupo; 

public:
    /**
     * Genera una instancia de jefe con un ID
     */
    Jefe(const int);

    /**
     * Agrega personal al grupo
     * @return retorna verdadero si añade el personal de lo contrario retorna falso
     */
    bool AgregarPersonal();

    /**
     * @return El grupo de becarios
     */
    std::vector<Becario> getGrupo() const;

    /**
     * Retorna el nuemro de integrantes del grupo
     */
    int getNumGrupo() const;

};
/**
 *  Sobrecarga del operador de inserción <<
 */
std::ostream& operator<<(std::ostream& os, const Becario& _jefe);

#endif // JEFE_H
