#ifndef ROL_H
#define ROL_H

#include <string>

#define NUM_ROLES 4
#define ROL_SOFTWARE 0
#define ROL_HARDWARE 1
#define ROL_DATOS 2
#define ROL_REDES 3

extern std::string roles[NUM_ROLES];

std::string getRol(int _idRol);

#endif // ROL_H
