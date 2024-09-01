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
 * sleep(@int) Permite pausar la ejecución del programa por n segundos
-------------------------------------------------------------------*/
#include <cstdlib>
/** 
 * Metodos utilizados
 * - exit()
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
#include <stdlib.h>
/**
 * srand()
 */
#include <time.h>
/**
 * time()
 */
using namespace std;

#define N_JEFE 2             // Numero de Jefes
#define SEM_JEFE 0           // Proceso JEFE
#define SEM_AYUDA 1          // Proceso Becario
#define SEM_HERRAMIENTAS 2   // Recoger Herramientas


union senum{
    int val;
};

#include "Edificio.h"
#include "Entorpecedor.h"

int main() {
    // srand(time(NULL));

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












    // // ------- Semaforos -------
    // int sem;
    // int r;
    // pid_t pid;
    // union senum arg;
    // struct sembuf MC_Libre = {SEM_JEFE, 1, 0};
    // struct sembuf MC_Ocupada = {SEM_JEFE, -1, 0};

    // sem = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    // if(sem == -1){
    //     perror("Error creando semaforos.");
    //     return -1;
    // }

    // arg.val = 1;
    // r = semctl(sem, SEM_JEFE, SETVAL, arg);
    // if(r == -1){
    //     perror("Error al inicar el semaforo JEFE");
    //     return -1;
    // }

    // // -------- Memoria compartida --------
    // key_t Clave;
    // int ID_Memoria;
    // Jefe* jefasos = NULL;

    // Clave = ftok("/bin/ls", 33);
    // if (Clave == -1) {
    //     cout << "No consigo clave para memoria compartida" << endl;
    //     exit(0);
    // }

    // ID_Memoria = shmget(Clave, (sizeof(Jefe) * N_JEFE), 0777 | IPC_CREAT);
    // if (ID_Memoria == -1) {
    //     cerr << "No se pudo obtener el ID para la memoria compartida" << std::endl;
    //     exit(1);
    // }

    // jefasos = (Jefe*)shmat(ID_Memoria, nullptr, 0);
    // if (jefasos == (void*)-1) {
    //     cout << "No consigo memoria compartida" << endl;
    //     exit(0);
    // }

    // for (int i = 0; i < N_JEFE; i++) {
    //     pid = fork();
    //     if (pid == -1) {
    //         cout << "Fallo al crear el nuevo proceso";
    //     }

    //     if (pid == 0) {
    //         r = semop(sem, &MC_Ocupada, 1);
    //         cout<< i << " a cerrado el cemaforo"<<endl;
    //         {
    //             cout << "Nuevo Proceso" << endl;
    //             Jefe nuevo(5);
    //             jefasos[i] = nuevo;
    //             for(int c = 0; c < 5; c++){
    //                 sleep(1);
    //             }
    //         }
    //         r = semop(sem, &MC_Libre, 1);
    //         cout<< i << " a abierto el cemaforo" << endl;

            

    //         exit(0);
    //     }
    // }

    // // Esperar a que todos los procesos hijos terminen
    // for (int i = 0; i < N_JEFE; i++) {
    //     wait(nullptr);
    // }

    // // Ahora es seguro imprimir los resultados
    // cout << "========================" << endl;
    // for (int i = 0; i < N_JEFE; i++) {
    //     cout << jefasos[i] << endl;
    // }

    // shmdt((void*)jefasos);
    // shmctl(ID_Memoria, IPC_RMID, (struct shmid_ds*)NULL);

    // pid = wait(&r);
	// while ( (pid !=-1) ||  (pid == -1 && errno == EINTR) )
	// 	pid = wait(&r);
	// 	r = semctl(sem, 0, IPC_RMID);

	// 	if (r == -1)
	// 		perror("Error eliminando semáforos.");

	// 	printf("Fin.\n");
    return 0;
}
