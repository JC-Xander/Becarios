#ifndef TAREA_H
#define TAREA_H

#include <vector>
#include <string>
#include <cstdlib>

#include "Rol.h"
/**
 * Tareas que se le asignara al personal
 */
class Tarea {
    private:
        int idRol;
        int idTarea;
        int dificultad;
        bool esElectrica;

public:
    Tarea();
    /**
     * Crea un nueva tarea
     * @param int Rol al que pertenece la tarea
     * @param int ID de la tarea
     * @param int Dificultad de la tarea
     */
    Tarea(const int);

    /**
     * @return Nombre de la tarea
     */
    std::string getNombreTarea() const;

    /**
     * @return Difucultad de la tarea
     */
    int getDificultad() const;
    
    /**
     * Verifica de forma aleatoria si la tarea tiene documentación
     * @return True si tiene documentación de lo contario retorna falso
     */
    bool getDocumentacion();
};

#endif // TAREA_H