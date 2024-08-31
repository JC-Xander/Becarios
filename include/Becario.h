#ifndef BECARIO_H
#define BECARIO_H

#include <iostream>
#include <string>
#include <sys/types.h>

/**
 * De esta clase se heradaran todos los componentes 
 * Crea un becario el cual almacenara su ID y el ID del proceso en el que se creo
 */
class Becario {
private:
    int ID;
    pid_t ID_Proceso;

public:
    /**
     * Crea un nuevo becario con un identificador
     */
    Becario(const int);

    /**
     * @return El ID del proceso en que se creo
     */
    pid_t getID_Proceso() const;

    /**
     * @return ID del Becario
     */
    int getID() const;
};
/**
 *  Sobrecarga del operador de inserción <<
 */
std::ostream& operator<<(std::ostream& os, const Becario& _becario);

#endif // BECARIO_H
