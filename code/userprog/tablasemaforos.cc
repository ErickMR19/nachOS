#include "tablasemaforos.h"
#include <iostream>

#define MAX_SEMAPHORES 120
#include <unistd.h>

#define ConsoleInput 0
#define ConsoleOutput 1
#define ConsoleError 2

tablaControladoraSemaforos::tablaControladoraSemaforos():
usage(0)
{
    mutexLock = new Lock("SEMAPHORE_MUTEX");
    semaforos = new Semaphore*[MAX_SEMAPHORES];
    semaforosMap = new BitMap(MAX_SEMAPHORES);
}

tablaControladoraSemaforos::~tablaControladoraSemaforos()
{
    cleanTable();
    delete semaforosMap;
    delete [] semaforos;
}

int tablaControladoraSemaforos::nuevoSemaforo(int valorInicial)
{
    mutexLock->Acquire();

    int indice = semaforosMap->Find();
    if(indice == -1 )
        return indice;

    semaforos[indice] = new Semaphore(currentThread->getName(), valorInicial );
    semaforosMap->Mark(indice);
    return indice;
}

int tablaControladoraSemaforos::destruirSemaforo(int semaforoID)
{
    if(semaforoID >= MAX_SEMAPHORES)
        return -1;

    if( semaforosMap->Test(semaforoID) ){
        delete semaforos[semaforoID];
        semaforosMap->Clear(semaforoID);
    }
    return 0;
}

int tablaControladoraSemaforos::semaforoSignal(int semaforoID)
{
    mutexLock->Acquire();

    if(semaforoID >= MAX_SEMAPHORES)
        return -1;

    if( semaforosMap->Test(semaforoID) ){
        semaforos[semaforoID]->V();
    }

    mutexLock->Release();

    return 0;
}

int tablaControladoraSemaforos::semaforoWait(int semaforoID)
{
    mutexLock->Acquire();

    if(semaforoID >= MAX_SEMAPHORES)
        return -1;

    if( semaforosMap->Test(semaforoID) ){
        semaforos[semaforoID]->P();
    }

    mutexLock->Release();

    return 0;
}

void tablaControladoraSemaforos::addThread()
{
    mutexLock->Acquire();

    ++usage;

    mutexLock->Release();
}

void tablaControladoraSemaforos::delThread()
{
    mutexLock->Acquire();

    --usage;
    if(!usage)
        cleanTable();

    mutexLock->Release();
}

void tablaControladoraSemaforos::Print() const
{
    mutexLock->Acquire();

    for(int i = 0; i < MAX_SEMAPHORES; ++i){
        if(semaforosMap->Test(i))
            std::cout << i << " : " << semaforos[i] << std::endl;
        else
            std::cout << i << " : " << "no está en uso" << std::endl;
    }

    mutexLock->Release();
}

void tablaControladoraSemaforos::cleanTable()
{
    mutexLock->Acquire();

    for(int i = 0; i < MAX_SEMAPHORES; ++i){
        if(semaforosMap->Test(i)){
            destruirSemaforo(i);
        }
    }

    mutexLock->Release();
}
