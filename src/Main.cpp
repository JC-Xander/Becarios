// ------- Librerias de Impresión -------
#include <iostream> 
/** 
 * Metodos utilizados
 * - cout: Permite imprimir en consola.
-------------------------------------------------------------------*/
#include <string>
/** 
 * Manejo de cadenas
-------------------------------------------------------------------*/
#include <stdio.h>
/** 
 * printf() Imprime en consola
 * perror() Imprime un mensaje de error relacionado con el valor actual 
 * de errno
 */
#include <errno.h>
/*------------------------------------------------------------------*/
// ----------- FIN -----------

// --------- Librerias de Memoria Compartida ------------
#include <sys/shm.h>
/** 
 * Usado para la creación de memoria compartida.
 * - ftok ("/bin/ls", @intClave): Crea una @Clave
 * - shmget (@Clave, sizeof(char)*100, 0777 | IPC_CREAT) : Reserva el 
 *      espacio en memoria y devuelve el ID
 * - (int *)shmat (Id_Memoria, (char *)0, 0) : Adjuntar un
 *      segmento de memoria compartida a la memoria del proceso
 * - shmdt((char *)Memoria) : Desadjuntar el segmento de memoria 
 *      compartida del espacio de direcciones del proceso.
 * - shmctl(Id_Memoria, IPC_RMID, (struct shmid_ds *)NULL) : Libera
 *      la memoria compartida.
-------------------------------------------------------------------*/
 // --------- FIN --------

// ------ Congelar Ejecución ------
#include <unistd.h>
/** 
 * Metodos utilizados
 * - sleep(@int) Permite pausar la ejecución del programa por n segundos
 * - getpid()
-------------------------------------------------------------------*/
#include <cstdlib>
/** 
 * Metodos utilizados
 * - exit()
 * - rand()
 * - srand()
-------------------------------------------------------------------*/


#include <sys/sem.h>
/** 
 * Me permite utilizar
 * - struct sembuf @name = {0, 1, 0};
 * - struct sembuf @name = {0, -1, 0};
 * semget(IPC_PRIVATE, 2, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR)
 *      Permite crear los semaforos en conjunto de
 */
#include <fcntl.h>
/* 
 * Otorga permisos
-----------------------------------------------------------------*/
#include <wait.h>
/**
 * Metodo Utilizados
 * - wait(): La utilizamos para que el proceso padre espera a que 
 *           finalicen los procesos hijos.
-------------------------------------------------------------------*/

// ------ Librerias Obsoletas en el programa ----- 
//#include <sys/ipc.h>
/** 
-------------------------------------------------------------------*/
//#include <sys/stat.h>
/** 
-------------------------------------------------------------------*/
//#include <fcntl.h>
/** 
-------------------------------------------------------------------*/
//#include <sys/sem.h> 
/** 
-------------------------------------------------------------------*/

// --------- LIBRERIAS PERSONALIZADAS ------------
//#include "Jefe.h"
/** 
-------------------------------------------------------------------*/
#include <time.h>
/**
 * time()
 */
using namespace std;

#define N_BECARIO 7
#define N_JEFE 1     // Numero de Jefes
#define SEM_JEFE 0           // Proceso JEFE
#define SEM_EDIFICIO 1
#define SEM_AYUDA 2          // Proceso Becario
#define SEM_JORNADA 3   // Revisar jornada
#define SEM_ENTORPECEDOR 4


union senum{
    int val;
};

#include "Edificio.h"
#include "Entorpecedor.h"
#include "Jefe.h"
#include "Tarea.h"
#include "Edificio.h"
#include "Personal.h"

int main() {
    // ----- PARA QUE LAS ACCIONES SEAN ALEATORIAS EN CADA EJECUCIÓN -----

    // Edificio B2(1);
    // for (int i = 0; i < NUM_AREA; i++){
    //     cout << B2.areaDisponible[i] << endl;
    // }

    // // -------- SIMULACIÓN DE ASIGNACIÓN DE AULAS ---------
    // for(int i = 0; i < 5; i++){
    //     int aulaAleatoria = rand() % 5;  
    //     cout << aulaAleatoria << ") ";

    //     if (B2.asignarArea(aulaAleatoria)){
    //         cout << "Se a ocupado el area -> " << B2.getData(aulaAleatoria).c_str() << "." << endl;
    //     }else{
    //         cout << B2.getArea(i) << " -> Esta ocupada." <<  endl;
    //         if(B2.getTotalAreasDisponibles() == 0){
    //             cout << "No hay areas disponibles" << endl;
    //             cout << "El Becario fue enviado a casa" << endl;
    //         }else{
    //             cout << "Asignando nueva Area" <<endl;
    //             int idAreaAsignada = B2.buscarAsignarArea();
    //             if (idAreaAsignada == -1){
    //                 cout << "No hay areas disponibles" << endl;
    //                 cout << "El Becario fue enviado a casa" << endl;
    //             }else{
    //                 cout << "Se a ocupado el area -> " << B2.getData(idAreaAsignada).c_str() << "." << endl;
    //             }
    //         }
    //     }
    // }

    // for (int i = 0; i < NUM_AREA; i++){
    //     cout << B2.areaDisponible[i] << endl;
    // }












    // ------- SEMAFOROS -------
    int sem;           // Clave de los semaforos
    int r;             // Estado en la creacion
    pid_t pid;         // Pid retornado por los fork() para jefe
    union senum arg;   // Valor inicial de los semaforos

    struct sembuf MC_Libre = {SEM_JEFE, 1, 0};               // Semaforo para Memoria compartida de Jefe
    struct sembuf MC_Ocupada = {SEM_JEFE, -1, 0};

    struct sembuf EDIFICIO_SUBE = {SEM_EDIFICIO, 1, 0};      // Semaforo para el acceso y modificacion de edifio
    struct sembuf EDIFICIO_BAJA = {SEM_EDIFICIO, -1, 0};

    struct sembuf AYUDA_SUBE = {SEM_AYUDA, 1, 0};           // Semeforo para acceder al metodo ayuda y Documentacion Jefe
    struct sembuf AYUDA_BAJA = {SEM_AYUDA, -1, 0};

    struct sembuf JORNADA_SUBE = {SEM_JORNADA, 1, 0};       // Semaforo para controlar la lectrura y el abance de la jornada
    struct sembuf JORNADA_BAJA = {SEM_JORNADA, -1, 0};

    struct sembuf ENTORPECEDOR_SUBE = {SEM_ENTORPECEDOR, 1, 0};   // semaforo para lectura y modificacion del entorpecedor
    struct sembuf ENTORPECEDOR_BAJA = {SEM_ENTORPECEDOR, -1, 0};

    sem = semget(IPC_PRIVATE, 5, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if(sem == -1){
        perror("Error creando semaforos.");
        return -1;
    }

    arg.val = 1;
    if (semctl(sem, SEM_JEFE, SETVAL, arg) == -1){
        perror("Error al inicar SEM_JEFE");
        return -1;
    }

    arg.val = 1;
    if (semctl(sem, SEM_EDIFICIO, SETVAL, arg) == -1){
        perror("Error al inicar SEM_EDIFICIO");
        return -1;
    }

    arg.val = 1;
    if (semctl(sem, SEM_AYUDA, SETVAL, arg) == -1){
        perror("Error al inicar SEM_AYUDA");
        return -1;
    }

    arg.val = 1;
    if (semctl(sem, SEM_JORNADA, SETVAL, arg) == -1){
        perror("Error al inicar SEM_HERRAMIENTAS");
        return -1;
    }

    arg.val = 1;
    if (semctl(sem, SEM_ENTORPECEDOR, SETVAL, arg) == -1){
        perror("Error al inicar SEM_ENTORPECEDOR");
        return -1;
    }

    // -------- MEMORIA COMPARTIDA --------
    key_t Clave;             // Clave para para la memoria
    int ID_Memoria;          // ID de la memeria
    Jefe* jefasos = NULL;    // Memoria compartida

    Clave = ftok("/bin/ls", 33);
    if (Clave == -1) {
        cout << "No consigo clave para memoria compartida" << endl;
        return -1;
    }

    ID_Memoria = shmget(Clave, (sizeof(Jefe) * N_JEFE), 0777 | IPC_CREAT);
    if (ID_Memoria == -1) {
        cerr << "No se pudo obtener el ID para la memoria compartida" << std::endl;
        return -1;
    }

    jefasos = (Jefe*)shmat(ID_Memoria, nullptr, 0);
    if (jefasos == (void*)-1) {
        cout << "No consigo memoria compartida" << endl;
        return -1;
    }

    // --- CREACION DE LOS PROCESOS JEFES ---
    for (int i = 0; i < N_JEFE; i++) {
        int idJefe;      // ID del Jefe
        int idEdificio;  // ID del edificio al que fue asignado;
        int posicion;    // posición en la que se guardara el jefe en memoria compartida

        pid = fork();
        if (pid == -1) {
            perror("Fallo la creación de un nuevo Proceso\n");
            exit(1);
        }

        if (pid == 0) {
            // Generando una semilla distinta en cada proceso jefe
            srand(time(NULL) + getpid());

            idJefe = i;
            posicion = i;

            if (idJefe >= NUM_EDIFICIO){
                // Nuevo proceso jefe sin edificio asignado.
                Jefe nuevoJefe(idJefe);
                cout << "Ya no hay edificios disponible para el Jefe -> " << idJefe << endl;

                if (semop(sem, &MC_Ocupada, 1) == -1) {
                    perror("Fallo al bajar el semaforo 0");
                    exit(1);
                }
                {
                    jefasos[posicion] = nuevoJefe;
                }
                if(semop(sem, &MC_Libre, 1) == -1) {
                    perror("Fallo al subir el semaforo 0");
                    exit(1);
                }
                
                cout << "El Jefe " << idJefe << " fue rebocado de su puesto" << endl;
                exit(0); // finalización del proceso jefe sin edificio asignado.
            }

            // ----- PROCESO JEFE CON EDIFICIO ASIGNADO ----
            idEdificio = i;
            Jefe nuevoJefe(idJefe, idEdificio);

            if (semop(sem, &MC_Ocupada, 1) == -1){
                perror("Fallo al bajar el semaforo 0");
                exit(1);
            }
            {
                jefasos[posicion] = nuevoJefe;
            }
            if(semop(sem, &MC_Libre, 1) == -1){
                perror("Fallo al subir el semaforo 0");
                exit(1);
            }

            // ------------ INICIO DE LA ACCIONES DE JEFE-BECARIO -----------

            int idBecario;      // ID del Becario
            int idArea;         // ID del area asignada
            int pidBecario;     // pid retornddo para el fork()
            int contArea;       // Areas disponibles en el edificio
            bool resultado;     // Guardara el resultado de la opreaciones realizadas
            Jefe* jefe;         // Jefe actual;

            for (int b = 0; b < N_BECARIO; b++){

                // --- EJECUTANDO EL PROCESO DEL PERSONAL ---
                pidBecario = fork();

                if(pidBecario == -1){
                    perror("No se pudo inicializar el nuevo proceso becario\n");
                    return -1;
                }

                if(pidBecario == 0){
                    jefe = &jefasos[posicion];
                    idBecario = b;
                    // Genera una nueva semilla aleatoria para cada proceso becario
                    srand(time(NULL) + getpid());

                    // --- SELECCIONANDO UN AREA DISPONIBLE DEL EDIFICIO ------
                    //No hay areas disponibles
                    if (semop(sem, &EDIFICIO_BAJA, 1) == -1){
                        perror("Fallo al bajar el semaforo 1");
                        exit(1);
                    }
                    {
                        contArea = jefe->getEdificio().getcontAreasDisponibles();
                    }
                    if (semop(sem, &EDIFICIO_SUBE, 1) == -1){
                        perror("Fallo al subir el semaforo 1");
                        exit(1);
                    }
                    if(!contArea){
                        cout << "Ya no hay areas Disponibles" << endl;
                        cout << "El becario " << idBecario << " fue suspendido por falta de areas";
                        exit(0); // finalizando proceso becario porque todas las areas ya fueron asignadas
                    }



                    //Verificcando las areas disponibles
                    idArea = rand() % NUM_AREA;

                    if (semop(sem, &EDIFICIO_BAJA, 1) == -1){
                        perror("Fallo al bajar el semaforo 1");
                        exit(1);
                    }
                    {
                        resultado = jefe->getEdificio().asignarArea(idArea);
                    }
                    if (semop(sem, &EDIFICIO_SUBE, 1) == -1){
                        perror("Fallo al subir el semaforo 1");
                        exit(1);
                    }
                    
                    // El area asignada se encontraba ocupada
                    if(!resultado){
                        cout << "El area " << Edificio::getArea(idArea) << " asignada al becario " << idBecario << " esta ocupada." << endl;
                        cout << "Asignandole una area nueva." <<endl;

                        if (semop(sem, &EDIFICIO_BAJA, 1) == -1){
                            perror("Fallo al bajar el semaforo 1");
                            exit(1);
                        }
                        {
                            idArea = jefe->getEdificio().buscarAsignarArea();
                        }
                        if (semop(sem, &EDIFICIO_SUBE, 1) == -1){
                            perror("Fallo al subir el semaforo 1");
                            exit(1);
                        }
                        if(idArea == -1){
                            cout << "Ya no hay areas Disponibles" << endl;
                            cout << "El becario " << idBecario << " fue suspendido por falta de aulas";
                            exit(0); // finalizando proceso becario porque to habian areas disponibles
                        }
                    }
                    // Se le asigno un area vacia al becario.
                    
                    // Creacion del personal con un rol aleatorio y el id del area al que fue asignado.
                    if (semop(sem, &MC_Ocupada, 1) == -1){
                        perror("Fallo al bajar el semaforo 0");
                        exit(1);
                    }
                    {
                        resultado = jefe->AgregarPersonal();
                    }
                    if(semop(sem, &MC_Libre, 1) == -1){
                        perror("Fallo al subir el semaforo 0");
                        exit(1);
                    }

                    // El becario asignado no se presento.
                    if(!resultado){
                        cout << "El Becario " << idBecario << " no se presento porque: " << Personal::circunstacias[rand() % CIRCUNSTANCIAS_PERSONAL] << endl;
                        if (semop(sem, &EDIFICIO_BAJA, 1) == -1){
                            perror("Fallo al bajar el semaforo 1");
                            exit(1);
                        }
                        {
                            jefe->getEdificio().desocuparArea(idArea);
                        }
                        if (semop(sem, &EDIFICIO_SUBE, 1) == -1){
                            perror("Fallo al subir el semaforo 1");
                            exit(1);
                        }
                        exit(0); // Finaliza el proceso porque el becario no se presento
                    };   

                    Personal becario((rand() % NUM_ROLES), idArea);
                    cout << "Al becario " << idBecario << " se le asigno el area : " << idArea << " y el rol: " << roles[becario.getIdRol()] << endl;

                    // ---- INICIA LA JORNADA LABORAL DEL BECARIO ----
                    while(true){
                        if(semop(sem, &JORNADA_BAJA, 1) == -1){
                            perror("Fallo al subir el semaforo 3");
                            exit(1);
                        }
                        {
                            resultado = jefe->PedirTarea(becario);
                        }
                        if(semop(sem, &JORNADA_SUBE, 1) == -1){
                            perror("Fallo al subir el semaforo 3");
                            exit(1);
                        }
                        if(!resultado){
                            cout << "La jornada finalizo el becario " << idBecario << " no puede recibir más tareas." << endl;
                            cout << "----- Becario " << idBecario << "Finalizo su jornada laboral -----" << endl; 
                            exit(0); // Finaliza el proceso becario por finalizacion de su jornada laboral. 
                        }

                        // Becario recibe una tarea
                        cout << "El jefe " << idJefe << " le asigno la tarea " << becario.getTareaAsignada().getNombreTarea() << " al becario " << idBecario << endl;
                        cout << "El becario realiza la tarea: " << becario.getTareaAsignada().getNombreTarea() << endl;

                        int resultadoTarea = COMPLETOTAREA;
                        // El becario inicia la ejecucion de la tarea
                        for (int d = 0; d < becario.getTareaAsignada().getDificultad(); d++){
                            sleep(1);

                            // Interrupcion dificultad
                            if (rand() % (8 - MAX_DIFICULTAD) == 0){
                                cout << "El becario " << idBecario << " a pedido ayuda al jefe" << endl;

                                if (semop(sem, &AYUDA_BAJA, 1) == -1){
                                    perror("Fallo al bajar el semaforo 2");
                                    exit(1);
                                }
                                {
                                    resultado = jefe->Ayuda();
                                }
                                if(semop(sem, &AYUDA_SUBE, 1) == -1){
                                    perror("Fallo al subir el semaforo 2");
                                    exit(1);
                                }
                                if(!resultado){
                                    cout << "El becario no recibio ayuda porque " << Jefe::circunstancias[rand() % CIRCUNSTANCIAS_JEFE] << endl;
                                    sleep(1);
                                    if((rand() % 2) == 0) {
                                        cout << "El becario " << idBecario << " abandonado la tarea porque no pudo realizarla" << endl;
                                        resultadoTarea = ABANDONATAREA;
                                        break;
                                    }
                                }else{
                                    cout << "Jefe ayudo al becario " << idBecario << endl;
                                }   
                            }

                            // Interrupción entorpecedor
                            
                            if ((rand() % 2) == 0){
                                int idObjetivo;
                                if (semop(sem, &ENTORPECEDOR_BAJA, 1) == -1){
                                    perror("Fallo al bajar el semaforo 4");
                                    exit(1);
                                }
                                {
                                    idObjetivo = jefe->getEntorpecedor().getIdBecario();
                                }
                                if(semop(sem, &ENTORPECEDOR_SUBE, 1) == -1){
                                    perror("Fallo al subir el semaforo 4");
                                    exit(1);
                                }  

                                if(idObjetivo == idBecario){
                                    if (semop(sem, &ENTORPECEDOR_BAJA, 1) == -1){
                                        perror("Fallo al bajar el semaforo 4");
                                        exit(1);
                                    }
                                    {
                                        resultado = jefe->getEntorpecedor().molestarBecario();
                                    }
                                    if(semop(sem, &ENTORPECEDOR_SUBE, 1) == -1){
                                        perror("Fallo al subir el semaforo 4");
                                        exit(1);
                                    }
                                    if(resultado){
                                        if(becario.disminuirCordura()){
                                            cout << "El becario " << idBecario << " a pedido ayuda al jefe con el entorpecedor." << endl;
                                            if (semop(sem, &AYUDA_BAJA, 1) == -1){
                                                perror("Fallo al bajar el semaforo 0");
                                                exit(1);
                                            }
                                            {
                                                resultado = jefe->Ayuda();
                                            }
                                            if(semop(sem, &AYUDA_SUBE, 1) == -1){
                                                perror("Fallo al subir el semaforo 1");
                                                exit(1);
                                            }
                                            
                                            if(resultado){
                                                cout << "Jefe " << idJefe << " a ayudado al becario " << idBecario << " con el entorpecedor." << endl;
                                            }else{
                                                cout << "El becario " << idBecario << " no recibio ayuda ya que el jefe " << Jefe::circunstancias[rand() % CIRCUNSTANCIAS_JEFE] << endl;
                                                cout << "El becario " << idBecario << " no soporta al entorpecedor " << endl;
                                                cout << "El becario " << idBecario << " a abandonado la tarea." << endl;
                                                resultadoTarea = ABANDONATAREA;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }

                            //Interrupción Jornada
                            int numJornada = 0;
                            if (semop(sem, &JORNADA_BAJA, 1) == -1){
                                perror("Fallo al bajar el semaforo 3");
                                exit(1);
                            }
                            {
                                numJornada = jefe->jornada;
                            }
                            if(semop(sem, &JORNADA_SUBE, 1) == -1){
                                perror("Fallo al subir el semaforo 3");
                                exit(1);
                            }
                            if(numJornada == 0){
                                cout << "------- La Jornada esta por terminar -------" << endl;
                                cout << "El becario " << idBecario << "Esta parcheando la tarea";
                                resultadoTarea = PARCHEOTAREA;
                                break;
                            }
                        } // ---- Sale de la ejecucion de tareas ---


                        if(resultadoTarea == COMPLETOTAREA){
                            cout << "El becario " << idBecario << " a completado la tarea: " << becario.getTareaAsignada().getNombreTarea() << endl; 
                        } 
                        if (jefe->getEntorpecedor().getIdBecario() == idBecario) {
                            // Asignando un nuevo becario al entorpecedor
                            cout << " El entorpecedor molestara a un nuevo becario " << endl;
                            if (semop(sem, &ENTORPECEDOR_BAJA, 1) == -1){
                                perror("Fallo al bajar el semaforo 4");
                                exit(1);
                            }
                            {
                                jefe->getEntorpecedor().setIdBecario(rand() % jefe->getContPersonal());
                            }
                            if(semop(sem, &ENTORPECEDOR_SUBE, 1) == -1){
                                perror("Fallo al subir el semaforo 4");
                                exit(1);
                            }
                            cout << "El nuevo objetivo del entorpecedor es el becario " << jefe->getEntorpecedor().getIdBecario() << endl;
                        }
                        if (semop(sem, &MC_Ocupada, 1) == -1){
                            perror("Fallo al bajar el semaforo 0");
                            exit(1);
                        }
                        {
                            if(resultadoTarea == COMPLETOTAREA)
                                jefe->tareaCompletada();
                            else if(resultadoTarea == ABANDONATAREA)
                                jefe->tareaAbandonada();
                            else
                                jefe->tareaParcheada();
                        }
                        if(semop(sem, &MC_Libre, 1) == -1){
                            perror("Fallo al subir el semaforo 1");
                            exit(1);
                        }

                        int numJornada = 0;
                        if (semop(sem, &JORNADA_BAJA, 1) == -1){
                            perror("Fallo al bajar el semaforo 3");
                            exit(1);
                        }
                        {
                            numJornada = jefe->jornada;
                        }
                        if(semop(sem, &JORNADA_SUBE, 1) == -1){
                            perror("Fallo al subir el semaforo 3");
                            exit(1);
                        }
                        if(numJornada == 0){
                            cout << "------- La Jornada a terminado -------" << endl;
                            exit(0);
                        }
                    }
                    exit(0); // Finaliza el Proceso becario;
                }
            }

            // Asignando un becario al entorpecedor
            if (semop(sem, &ENTORPECEDOR_BAJA, 1) == -1){
                perror("Fallo al bajar el semaforo 4");
                exit(1);
            }
            {
                jefasos[posicion].getEntorpecedor().setIdBecario(rand() % jefasos[posicion].getContPersonal());
            }
            if(semop(sem, &ENTORPECEDOR_SUBE, 1) == -1){
                perror("Fallo al subir el semaforo 4");
                exit(1);
            }
            cout << "El entorpecedor a empezado a molestar al becario " << jefasos[posicion].getEntorpecedor().getIdBecario() << endl;

            // Inicialdo jornada()
            int pidJornada = fork();

            if (pidJornada == -1){
                perror("No se pudo inicializar el nuevo proceso becario\n");
                    return -1;
            }

            if (pidJornada == 0){
                for (int j = 0; j < JORNADA; j++){
                    sleep(2);
                    if (semop(sem, &JORNADA_BAJA, 1) == -1){
                        perror("Fallo al bajar el semaforo 3");
                        exit(1);
                    }
                    {
                        jefasos[posicion].jornada--;
                    }
                    if(semop(sem, &JORNADA_SUBE, 1) == -1){
                        perror("Fallo al subir el semaforo 3");
                        exit(1);
                    }
                }
                exit(0);
            }

            for(int n = 0; n < N_BECARIO + 1; n++){
                wait(nullptr);
            }
            cout << "Jefe " << idJefe << " a terminado su jornada" << endl;
            exit(0); // ----- FINALIZA EL PROCESO JEFE -----
        }
    }



    // Esperar a que todos los procesos hijos terminen
    for (int i = 0; i < N_JEFE; i++) {
        wait(nullptr);
    }

    // Ahora es seguro imprimir los resultados
    cout << "========================" << endl;
    for (int i = 0; i < N_JEFE; i++) {
        Jefe jefeActual = jefasos[i];

        if(jefeActual.getEdificio().getIdEdificio() == -1){
            cout << "¿----- ESTADISTICAS JEFE " << jefeActual.getIdJefe() << " ------?" << endl;
            cout << "-> Suspendido por falta de edificios" << endl;
            cout << "-------------------------------------------------\n" << endl;
            continue;
        }

        cout << "¿----- ESTADISTICAS JEFE " << jefeActual.getIdJefe() << " ------?" << endl;
        cout << "-> Edificio: " << jefeActual.getEdificio().getEdificio() << endl;
        cout << "-> Becarios a cargo : " << jefeActual.getContPersonal() << endl; 
        cout << "-> Tareas Completadas: " << jefeActual.getContTareasCompletados() << endl;
        cout << "-> Tareas Abandonadas: " << jefeActual.getContTareasAbandonadas() << endl;
        cout << "-> Tareas Parcheadas: " << jefeActual.getContTareasParcheadas() << endl;
        cout << "-------------------------------------------------\n" << endl;
    }

    shmdt((void*)jefasos);
    shmctl(ID_Memoria, IPC_RMID, (struct shmid_ds*)NULL);

	while ( (pid !=-1) ||  (pid == -1 && errno == EINTR) ) {
		pid = wait(&r);
		r = semctl(sem, 0, IPC_RMID);

		if (r == -1)
			perror("Error eliminando semáforos.");
    }

	printf("Fin.\n");
    return 0;
}
