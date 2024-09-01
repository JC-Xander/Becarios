#ifndef ENTORPECEDOR_H
#define ENTORPECEDOR_H

#include <iostream>
#include <string>
#include <stdlib.h>


#include "Becario.h"

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
        int edificio;
    
    public:
        Entorpecedor(const int);
        bool setIdBecario(const int);
        bool MolestarBecario();
        bool FinalizoTarea();
};

#endif // Entorpecedor