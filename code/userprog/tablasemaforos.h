#ifndef TABLASEMAFOROS_H
#define TABLASEMAFOROS_H

#include "synch.h"
#include "bitmap.h"

extern Thread *currentThread;

class tablaControladoraSemaforos
{
public:
    tablaControladoraSemaforos();
    ~tablaControladoraSemaforos();

    int nuevoSemaforo( int valorInicial ); // Crea un semaforo
    int destruirSemaforo( int semaforoID );      // Destruye un semaforo
    int semaforoSignal( int semaforoID ) ;  // hace signal a un semaforo
    int semaforoWait( int semaforoID ) ; // hace wait a un semaforo
    void addThread();		// If a user thread is using this table, add it
    void delThread();		// If a user thread is using this table, delete it

    void Print() const;

  private:
    Semaphore **semaforos;		// A vector with user opened files
    BitMap * semaforosMap;	// A bitmap to control our vector
    Lock * mutexLock;  // A mutex lock to assure that no other process is trying to modify the same semaphore at the same time
    int usage;			// How many threads are using this table
    void cleanTable(); // Cierra todos los archivos de la tabla

};

#endif // TABLASEMAFOROS_H
