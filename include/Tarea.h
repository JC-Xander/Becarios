#ifndef TAREA_H
#define TAREA_H

#include <string>
#include <iostream>

/**
 * Tareas que se le asignara al personal
 */
class Tarea {
private:
    std::string nombre; 
    int dificultad;
    bool esElectrica;

public:
    /**
     * Crea un nueva tarea
     * @param string Nombre de la tarea
     * @param int Dificultad de la tarea
     * @param bool Ocupa electricidad
     */
    Tarea(const std::string, int, bool);

    /**
     * @return Nombre de la tarea
     */
    std::string getNombre() const;

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
/**
 *  Sobrecarga del operador de inserción <<
 */
std::ostream& operator<<(std::ostream& os, const Tarea& _tarea);

#endif // TAREA_H