#ifndef ENTORPECEDOR_H
#define ENTORPECEDOR_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "Edificio.h"

#define NUM_ACCIONES 7

class Entorpecedor {
    private:
        std::string acciones[NUM_ACCIONES] = { 
            "Distraer con conversaciones innecesarias",
            "Pedir ayuda constante con tareas simples",
            "Interrumpir con chistes o comentarios fuera de lugar",
		    "Enviar mensajes de chat o correos electrónicos no urgentes",
            "hacer ruido constante (por ejemplo, con música alta o sonidos molestos)",
            "organizar reuniones innecesarias",
		    "preguntar continuamente sobre el progreso de tareas no prioritarias"
        };
        int idBecario;
        int idEdificio;
    
    public:
        Entorpecedor();
        Entorpecedor(const int);
        int getIdBecario();
        bool setIdBecario(const int);
        bool molestarBecario();
        bool FinalizoTarea();
};

#endif // Entorpecedor