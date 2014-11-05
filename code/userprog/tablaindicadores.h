#ifndef TABLAPROCESOS_H
#define TABLAPROCESOS_H

#include "synch.h"
#include "bitmap.h"
#include "thread.h"
#include "list.h"

#define MAX_PROCESS 120

#include "tablaarchivos.h"

class tablaIndicadoresProcesos
{
public:
    tablaIndicadoresProcesos();
    ~tablaIndicadoresProcesos();

    int RegisterProcess( Thread* hilo ); // Register the process ID
    int RegisterProcess(Thread* hilo, int parentPid);
    void DeRegisterProcess( int pid, int exitStatus );      // Unregister the process ID
    bool isRegistered( int pid );     // Checks if a process ID is already registered
    Thread* getThread( int pid ) const;     // returns the Thread pointer to the given process ID
    bool IsIncluded(Thread* hilo);          // Checks if the given Thread's pointer is included in the table

    void Print();               // Print contents
    void setStatus(int pid,int i);
    int Join(int pid);
    tablaControladoraArchivos* getTablaArchivos(int pid);
    tablaControladoraArchivos* getTablaArchivos(Thread* hilo);
  private:
    //mantiene de una mejor forma los datos de cada proceso
    struct Process{
      int pid;
      int parentPid;
      int *exitStatus;
      Thread* thread;
      tablaControladoraArchivos* tablaArchivos;
      // guarda todos los procesos que le hayan hecho join, y los vuelve a correr al salir
      List<int> waiting;
      Process():exitStatus(NULL),tablaArchivos(new tablaControladoraArchivos()){}
      ~Process(){if(exitStatus) delete exitStatus; if(tablaArchivos) delete tablaArchivos;}
    };

    Process *runningProcesses;		// A vector with user running processes
    Lock processesMutexLock; // A mutex lock to assure that no other process is trying to modify the table at the same time
    BitMap runningProcessesMap;	// A bitmap to control our vector
    bool * recursos;
    int usage;	     	// How many threads are using this table
    void cleanTable(); // Elimina todas las asociaciones entre
};

#endif // TABLAPROCESOS_H
