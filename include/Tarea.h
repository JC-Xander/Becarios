#ifndef TAREA_H
#define TAREA_H

#include <stdlib.h>
#include <unistd.h>

/**
 * Tareas que se le asignara al personal
 */
class Tarea {
private:
    int idTarea;
    int dificultad;
    bool esElectrica;

public:
    /**
     * Crea un nueva tarea
     * @param string Nombre de la tarea
     * @param int Dificultad de la tarea
     * @param bool Ocupa electricidad
     */
    Tarea(const int, int);

    /**
     * @return Nombre de la tarea
     */
    int getIdTarea() const;

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