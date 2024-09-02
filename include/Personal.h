#ifndef PERSONAL_H
#define PERSONAL_H

#include <cstdlib>
#include <string>
#include "Tarea.h"
#include "Rol.h"

#define CIRCUNSTANCIAS_PERSONAL 3

#define ABANDONATAREA 0
#define COMPLETOTAREA 1
#define PARCHEOTAREA 2

class Personal {
    private:
        int idRol;
        int idArea;
        int cordura;
        Tarea tareaAsignada;

    public:
        static std::string circunstacias[CIRCUNSTANCIAS_PERSONAL];

        Personal(int _idRol, int _idArea);
        std::string getRolAsignado();
        Tarea getTareaAsignada();
        int getIdRol();
        void setAsignarTarea(Tarea _tarea);
        bool disminuirCordura();
};

#endif // PERSONAL_H