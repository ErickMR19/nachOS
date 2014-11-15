// exception.cc
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tablaindicadores.h"
#include "../threads/synch.h"
#include "../machine/machine.h"
#include "../threads/utility.h"
#include <string.h>
#include <errno.h>


#define FALSE 0
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions
//	are in machine.h.
//----------------------------------------------------------------------
// se inicia con uno, para que la primer uso no se quede esperando una señal
    Semaphore * consola = new Semaphore("Semaforo de consola", 1);
/**
  * 	modifica los registros, para que una vez que el programa retorna, prosiga
  *   y no se quede enciclado en el llamado
  **/
void returnFromSystemCall()
{

    int pc, npc;

    pc = machine->ReadRegister( PCReg );
    npc = machine->ReadRegister( NextPCReg );
    machine->WriteRegister( PrevPCReg, pc );        // PrevPC <- PC
    machine->WriteRegister( PCReg, npc );           // PC <- NextPC
    machine->WriteRegister( NextPCReg, npc + 4 );   // NextPC <- NextPC + 4

}       // returnFromSystemCall

/**
  * 	apaga el sistema
  **/
void Nachos_Halt()
{                    // System call 0

    DEBUG('a', "Shutdown, initiated by user program.\n");
    delete consola;
    interrupt->Halt();

}//NACHOS_HALT

/**
  * 	termina el hilo actual
  **/
void Nachos_Exit()
{
    DEBUG('E',"Entrando Syscall EXIT. By: '%s'\n",currentThread->getName());
    tablaProcesos->DeRegisterProcess(tablaProcesos->RegisterProcess(currentThread),0);
    DEBUG('E',"EXIT. Luego de despertar a los otros. By: '%s'\n",currentThread->getName());
    currentThread->Finish();
    returnFromSystemCall();
}

/**
  * 	metodo auxiliar utilizado por el llamado exec
  *   recibe un puntero a un hilo, para verificar que este es quien se esta ejecutando
  *   actualmente
  *   pone el hilo en la cola para ejecutarse
  **/
void EjecutarEnEspacio(void* hilo)
{
  ASSERT(currentThread == hilo);
  currentThread->space->InitRegisters();		// inicializa el espacio
	currentThread->space->RestoreState();
  //scheduler->ReadyToRun(currentThread);
  machine->Run();
}//EJECUTARENESPACIO

/**
 * 	Se encarga de leer de la memoria de nachos, la cantidad indica de caracteres
 *  en la direccion indicada, y los copia en la variable pasada como buffer
 **/
void leerDeMemoria(int direccionMemoria,char* buffer,int cantidad){
    bool noError = true;
    int i = 0;
    do{
        noError = machine->ReadMem(direccionMemoria+i, 1, (int*)(buffer+i));
        ++i;
    }while(noError && i < cantidad);
}//LEERDEMEMORIA

/**
  * 	Se encarga de copiar en la memoria de nachos, la cantidad indica de caracteres
  *  en la direccion indicada, lo que se encuentra a partir de la direccion apuntada
  *  por el parametro origen
  **/
bool copiarAMemoria(int addrNachos, int size, char* origen){
  bool noError = true;
  for(int i = 0; i < size && noError; ++i)
    noError = machine->WriteMem(addrNachos+i, 1, (int)(origen[i]));
  return noError;
}//COPIARAMEMORIA

/**
  * 	metodo auxiliar utilizado por el llamado fork
  *   recibe un puntero a la función a correr
  **/
void NachosForkThread( void* arg )
{

    AddrSpace *space;
    long p = (long)arg;
    space = currentThread->space;
    space->InitRegisters();             // set the initial register values
    space->RestoreState();              // load page table register

    // Set the return address for this thread to the same as the main thread
    // This will lead this thread to call the exit system call and finish
    machine->WriteRegister( RetAddrReg, 4 );

    machine->WriteRegister( PCReg, p );
    machine->WriteRegister( NextPCReg, p + 4 );

    machine->Run();                     // jump to the user progam
    ASSERT(FALSE);

}

/**
  * 	permite crear un nuevo hilo compartiendo el espacio de codigo y de datos
  *   de un hilo padre
  **/
void Nachos_Fork()
{			// System call 9

    DEBUG( 'E', "Entering Fork System call\n" );
    // We need to create a new kernel thread to execute the user thread
    Thread * nuevoThread = new Thread( "child to execute Fork code" );
    int id = tablaProcesos->RegisterProcess(currentThread);
    tablaProcesos->RegisterProcess(nuevoThread,id);
    // Child and father will also share the same address space, except for the stack
    // Text, init data and uninit data are shared, a new stack area must be created
    // for the new child
    // We suggest the use of a new constructor in AddrSpace class,
    // This new constructor will copy the shared segments (space variable) from currentThread, passed
    // as a parameter, and create a new stack for the new
    nuevoThread->space = new AddrSpace(currentThread->space);

    nuevoThread ->Fork( NachosForkThread, (void*)machine->ReadRegister( 4 ) );

    returnFromSystemCall();	// This adjust the PrevPC, PC, and NextPC registers
    DEBUG( 'u', "Exiting Fork System call\n" );
}	// Kernel_Fork

/**
  *Recibe el nombre de un programa y lo ejecuta. Devuelve el pid de este
  **/
void Nachos_Exec()
{
    DEBUG('E',"Entrando Syscall EXEC\n");
    char * filename = new char[100];
    // lee el nombre del archivo y lo guarda en filename
    leerDeMemoria(machine->ReadRegister(4),filename,100);
    // abre el archivo ejecutable
    OpenFile *executable = fileSystem->Open(filename);
    if (executable == 0) {
  		printf("Error, unable to open file: [%s]\n", filename);   ///ABORT program?
  		exit(-1);
	  }
    DEBUG('E',"Va a ejecutar: [%s]\n", filename);   ///ABORT program?
    // crea un nuevo hilo
    Thread* nuevoHilo = new Thread(filename);
    // crea un nuevo espacio de memoria para el ejecutable
    AddrSpace * espacio = new AddrSpace(executable);
    //Asigna el espacio de memoria creado al hilo
    nuevoHilo->space = espacio;
    // obtiene un pid para el proceso
    int pidParent = tablaProcesos->RegisterProcess(currentThread);
    int pid = tablaProcesos->RegisterProcess(nuevoHilo,pidParent);
    // ejecuta el ejecutable
    nuevoHilo->Fork( EjecutarEnEspacio, (void*)nuevoHilo );
    // devuelve el pid del proceso
    machine->WriteRegister(2,pid);

    DEBUG('E',"Saliendo Syscall EXEC\n");
    returnFromSystemCall();
}

/**
 * 	recibe un indicador del proceso y se espera hasta que este termine
 *
 **/
void Nachos_Join(){
    DEBUG('E',"Entrando Syscall JOIN\n");
    SpaceId pid  = machine->ReadRegister(4); 				// identificador del proceso
    Thread * thread;
    thread = tablaProcesos->getThread(pid);
    DEBUG('E',"Volvi luego de esperar el JOIN\n");
    returnFromSystemCall();
}

/**
  *  Se encarga de leer el nombre deseado del archivo y crea dicho archivo.
  **/
void Nachos_Create(){
  DEBUG('E',"Entrando Syscall CREATE\n");
  // buffer para el nombre del archivo
  char bufferString[100];
  // comprobador para verificar si se puedo crear el archvio
	int res = 0;
  // lee el nombre del archivo, la direccion esta contenida en el registro 4
	leerDeMemoria(machine->ReadRegister(4),bufferString,100);
	res = creat(bufferString, S_IRUSR | S_IWUSR);
	DEBUG('E',"Nachos_Create() ... Nombre: '%s'   ID: %i\n",bufferString,res);
	if(res == -1)
		printf ("Error creando el archivo %s. <---> %s\n",strerror(errno));
    ASSERT( res != -1);
    returnFromSystemCall();
}

/**
  *  Recibe el nombre de un archivo y trata de abrirlo. Retorna el identificador
  **/
void Nachos_Open()
{
    int idArchivoUnix = -1;
    int idArchivoNachos = -1;
    char * filename = new char[100];
    // lee el nombre del archivo y lo guarda en filename
    leerDeMemoria(machine->ReadRegister(4),filename,100);
    // abre el archivo
    idArchivoUnix = open(filename,O_RDWR);
	  DEBUG('E',"Nachos_Open() ... Nombre archivo: '%s' idUnix: %i\n",filename,idArchivoUnix);
        if(idArchivoUnix != -1) {
           // lo agrega a la tabla y obtiene el identificador para nachos
           idArchivoNachos = tablaProcesos->getTablaArchivos(currentThread)->Open(idArchivoUnix);
        }
        else{
          printf("Archivo no encontrado o inaccesible: [%s]\n",filename);
          ASSERT(0);
        }
    // se retorna el identifcador de nachos
    machine->WriteRegister(2,idArchivoNachos);
    delete [] filename;
    returnFromSystemCall();
}// Nachos_Open


/**
  * 	Se encarga de leer datos de un archivo abierto indicado por el usuario
  *  (puede ser de la consola también)
  **/
void Nachos_Read(){
    // direccion a la cual copiar
    int bufferACopiar = machine->ReadRegister(4);
    //cantidad a leer
    int cantidad = machine->ReadRegister(5);
    //identificador del archivo del cual leer
    OpenFileId identificadorArchivo = machine->ReadRegister(6);

    int cantidadLeida = 0;
    //buffer temporal en donde se escribira
    char * bufferTemporal;
    bufferTemporal = new char[cantidad];

    DEBUG('E',"Tamaño del mensaje a leer: %i ID: %i\n", cantidad, identificadorArchivo);

    consola->P();
    switch(identificadorArchivo){
        case ConsoleInput:
            cantidadLeida = read(1, bufferTemporal, cantidad);
            // escribe del buffer temporal a la direccion indicada
            copiarAMemoria(bufferACopiar,cantidadLeida,bufferTemporal);
            // retorna la cantidad de bytes leidos
            machine->WriteRegister(2, cantidadLeida);
            break;
        case ConsoleOutput:
            machine->WriteRegister(2, -1); //ver la vara xq hay q copiarlo a memoria de nachos xq no lo puede ver
            printf("Leer desde la salida de consola no es posible. Eliminando programa");
            break;
        case ConsoleError:
            printf("Error %d\n", machine->ReadRegister(4));
            break;
        default:
            if(! ( tablaProcesos->getTablaArchivos(currentThread)->isOpened(identificadorArchivo) )){
                machine->WriteRegister(2, -1);
            }
            else{
                int archivoUnix = tablaProcesos->getTablaArchivos(currentThread)->getUnixHandle(identificadorArchivo);
                cantidadLeida = read(archivoUnix, bufferTemporal, cantidad);
                // escribe del buffer temporal a la direccion indicada
                copiarAMemoria(bufferACopiar,cantidadLeida,bufferTemporal);
                // retorna la cantidad de bytes leidos
		            machine->WriteRegister(2, cantidadLeida);
            }
    }
    consola->V();
    delete[] bufferTemporal;
    DEBUG('E',"SALIENDO DEL READ\n");
    returnFromSystemCall();
}



/**
  * 	Se encarga de escribir datos en un archivo abierto indicado por el usuario
  *  (puede ser en la consola también)
  **/
void Nachos_Write() {
    // direccion de datos a escribir
    int bufferDatos = machine->ReadRegister(4);
    // cantidad de datos a escribir
    int cantidad = machine->ReadRegister(5);
    //archivo al cual escribir
    OpenFileId identificadorArchivo = machine->ReadRegister(6);
    //buffer temporal para leer
    char *bufferTemporal = new char[cantidad+1];
    int archivoUnix = -1;
    //escribe lo que se quiere leer en el buffer temporal
    leerDeMemoria(bufferDatos,bufferTemporal,cantidad);
    DEBUG('E',"Tamaño del mensaje a escribir: %i ID: %i\n", cantidad, identificadorArchivo);

    // Need a semaphore to synchronize access to console
    consola->P();
    switch (identificadorArchivo) {
        case  ConsoleInput:	// User could not write to standard input
            machine->WriteRegister( 2, -1 );
            break;
        case  ConsoleOutput:
            bufferTemporal[cantidad] = 0;
            // escribe el buffer temporal en la stdout
            printf( "%s", bufferTemporal);
            break;
        case ConsoleError:	// This trick permits to write integers to console
            printf( "%d\n", machine->ReadRegister( 4 ) );
            break;
        default:	// All other opened files
            archivoUnix = tablaProcesos->getTablaArchivos(currentThread)->getUnixHandle(identificadorArchivo);
            DEBUG('E',"Luego de obtener tabla\n");
            if(archivoUnix == -1) // error al recuperar el UnixHandle
                machine->WriteRegister( 2, -1 );
            else{
                // escribe el buffer temporal en el archivo
                if( write(archivoUnix, (void*)bufferTemporal, cantidad) == -1)
                   //error al leer
                    machine->WriteRegister( 2, -1 );
            }


    }
    DEBUG('E',"Luego de escribir\n");
    consola->V();
    DEBUG('E',"SALIENDO DEL WRITE\n");
    returnFromSystemCall();		// Update the PC registers
}//NACHOS_WRITE

/**
 * 	Cierra un archivo
 *
 **/
void Nachos_Close(){
    DEBUG('E',"Entrando Syscall CLOSE\n");
    int archivo = machine->ReadRegister(4);
    if(tablaProcesos->getTablaArchivos(currentThread)->isOpened(archivo)){
        // recupera el identificador del archivo, y lo cierra si esta abierto
        close(tablaProcesos->getTablaArchivos(currentThread)->Close(archivo));
        DEBUG('E',"Se ha cerrado el archivo correctamente\n");
    }
    returnFromSystemCall();
}//NACHOS_CLOSE

/**
  * 	Pone a correr otro proceso, si está listo para correr
  *
  **/
void Nachos_Yield(){
    DEBUG('E',"Entrando Syscall YIELD\n");
    currentThread->SaveUserState();
    currentThread->space->SaveState();
    currentThread->Yield();
    returnFromSystemCall();
}//NACHOS_YIELD

/**
  * 	Crea un nuevo semafor y devuelve su id
  *
  **/
void Nachos_SemCreate()
{
    int valorInicial = machine->ReadRegister(4);
    int id = tablasSemaforos->nuevoSemaforo(valorInicial);
    machine->WriteRegister( 2, id );
    returnFromSystemCall();
}

/**
  * 	Destruye el semaforo indicado
  *
  **/
void Nachos_SemDestroy()
{
    int id = machine->ReadRegister(4);
    tablasSemaforos->destruirSemaforo(id);
    returnFromSystemCall();
}

/**
  * 	hace un signal al semaforos indicado
  *
  **/
void Nachos_SemSignal()
{
    int id = machine->ReadRegister(4);
    tablasSemaforos->semaforoSignal(id);
    returnFromSystemCall();

}


/**
  * 	pone el semaforo solicitado en espera
  *
  **/
void Nachos_SemWait()
{
    int id = machine->ReadRegister(4);
    tablasSemaforos->semaforoWait(id);
    returnFromSystemCall();
}



/**
 * 	Se encarga de reconocer el system call y llamar al metodo correspondiente
 *
 **/
void ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);
    DEBUG( 'u', "Invocado exception: %i\n",type);
    switch(which){

        case SyscallException:
            switch ( type ) {
            case SC_Halt:
                Nachos_Halt();             // System call # 0
                break;
            case SC_Exit:
                Nachos_Exit();             // System call # 1
                break;
            case SC_Exec:
                Nachos_Exec();
                break;
            case SC_Join:
                Nachos_Join();
                break;
      	    case SC_Create:
      		    Nachos_Create();
      		    break;
      	    case SC_Open:
                Nachos_Open();             // System call # 5
                break;
      	    case SC_Read:
      		    Nachos_Read();
      		    break;
            case SC_Write:
                Nachos_Write();             // System call # 7
                break;
            case SC_Close:
                Nachos_Close();             // System call # 8
                break;
      	    case SC_Fork:
                Nachos_Fork();             // System call # 9
                break;
            case SC_Yield:
                Nachos_Yield();            // System call # 10
                break;
            case SC_SemCreate:
                Nachos_SemCreate();         // System call # 11
                break;
            case SC_SemDestroy:
                Nachos_SemDestroy();        // System call # 12
                break;
            case SC_SemSignal:
                Nachos_SemSignal();         // System call # 13
                break;
            case SC_SemWait:
                Nachos_SemWait();           // System call # 14
                break;
            default:
                printf("Unexpected syscall exception %d\n", type );
                ASSERT(FALSE);
                break;
            }
            break;
        case PageFaultException:
            DEBUG('P',"Ha ocurrido un PageFaultException.\n");
            ASSERT(FALSE);
        default:
            printf( "Unexpected exception %d\n", which );
            ASSERT(FALSE);
        break;



    }
}
