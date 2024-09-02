#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
#include <string>

#define NUM_EDIFICIO 5
#define NUM_AREA 5

extern const std::string edificio[NUM_EDIFICIO];

extern const std::string area[NUM_AREA];

class Edificio {
    private:
        int edificioActual;
        int contAreasDisponibles;
        bool areaDisponible[NUM_AREA];

    public:
        Edificio();
        Edificio(int);
        int getcontAreasDisponibles();
        bool asignarArea(int);
        bool desocuparArea(int);
        int buscarAsignarArea();
        int getIdEdificio();
        std::string getEdificio();
        static std::string getArea(int);
        std::string getData(int);
        static std::string getNombreEdificio(int);

};
#endif // EDIFICIO_H