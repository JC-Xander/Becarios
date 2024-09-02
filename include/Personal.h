#ifndef PERSONAL_H
#define PERSONAL_H

#include <cstdlib>
#include <string>
#include "Tarea.h"
#include "Rol.h"

class Personal {
    private:
        int idRol;
        int idArea;
        int cordura;
        Tarea tareaAsignada;

    public:
        Personal(int _idRol, int _idArea);
        std::string getRolAsignado();
        Tarea getTareaAsignada();
        int getIdRol();
        void setAsignarTarea(Tarea _tarea);
};

#endif // PERSONAL_H