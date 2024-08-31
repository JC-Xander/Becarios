
cmake_minimum_required(VERSION 3.30)
# Nombre del proyecto
project(Proyecto-Becarios CXX)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 23)

#
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir el directorio de encabezados
#include_directories(include)

# Agregar el subdirectorio de la fuente
#add_subdirectory(src)

# Especificar los archivos de salida
add_executable(Prueba PruebaMemoria.cpp)

# Vincular las bibliotecas con el ejecutable principal
#target_link_libraries(BecarioRun Becario Jefe Tarea)
