#ifndef JEFE_H
#define JEFE_H

#include <iostream>
#include <vector> 
#include <cstdlib>
#include <unistd.h>
#include <string>

#include "Entorpecedor.h"
#include "Edificio.h"
#include "Rol.h"
#include "Tarea.h"
#include "Personal.h"

#define JORNADA 20
#define CIRCUNSTANCIAS_JEFE 2

class Jefe {
private:
    int idJefe;
    Edificio edificio;
    Entorpecedor entorpecedor;
    int contPersonal; 
    int contTareasCompletadas;
    int contTareasAbandonadas;
    int contTareasParcheadas;
    

public:
    int jornada;
    static std::string circunstancias[CIRCUNSTANCIAS_JEFE];
    // ---------------- CONSTRUCTORES --------------
    /**
     * Crea una instancia jefe dejando sus variables con los valores por defecto.
     */
    Jefe(int);
    /**
     * Genera una instancia de jefe con los valores inicializados para su ejecucucio.
     * @param _iD : identificador.
     * @param _idEdificio : Identificador del edificion asignado.
     */
    Jefe(const int _ID, int _idEdificio);

    // ----------- GETTERS ---------------
    /**
     * @return : edificio del jefe.
     */
    Edificio& getEdificio();
    /**
     * @return : Identificador del jefe
     */
    Entorpecedor& getEntorpecedor();
    int getIdJefe();
    /**
     * @return : Numero de tareas completadas
     */
    int getContTareasCompletados();
    /**
     * @return : Numero de tareas completadas
     */
    int getContTareasAbandonadas();
    /**
     * @return : Numero de becarios que el jefe tiene a cargo.
     */
    int getContPersonal();
    /**
     * 
     */
    int getContTareasParcheadas();
    /**
     * 
     */
    void tareaCompletada();
    /**
     * 
     */
    void tareaAbandonada();
    /**
     * 
     */
    void tareaParcheada();

    // ----------- METODOS ----------------
    /**
     * Agregar personal al grupo y crea un nuevo proceso para el.
     */
    bool AgregarPersonal();

    /**
     * Asigna una tarea
     * @param _personal : Personal al que le enviara la nueva tarea.
     * @return Si la jornada esta activa asigna una tarea al becario y retorna verdadero de los contrario retorna falso
     */
    bool PedirTarea(Personal& _personal);

    /**
     * Ayuda a un becario ya sea por problemas con las tareas o problemas
     * con el entorpecedos
     * @return Si fue ayudado retorna verdadero de lo contrario retorna falso.
     */
    bool Ayuda();

    /**
     * Solicita la documentación de la tarea al jefe
     *  @return si el jefe cuanta con la documentación retorna verdadero de lo contrario retorna falso
     */
    bool pedirDocumentacion();

};

#endif // JEFE_H
