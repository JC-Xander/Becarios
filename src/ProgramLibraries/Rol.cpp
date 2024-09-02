#include "Rol.h"

std::string roles[NUM_ROLES] = {
    "Software",
    "Hardware",
    "Datos",
    "Redes"
};

std::string getRol(int _idRol) {
    return roles[_idRol];
}
