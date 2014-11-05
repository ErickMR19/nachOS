#include "tablaarchivos.h"
#include <iostream>
#include "system.h"
#include <unistd.h>

#define ConsoleInput 0
#define ConsoleOutput 1
#define ConsoleError 2

tablaControladoraArchivos::tablaControladoraArchivos()
{
    openFiles = new int[MAX_FILES];
    for(int i = 3; i < MAX_FILES; ++i){
      openFiles[i] = -1;
    }
    mutexLock = new Lock("FILE_MUTEX");
    openFiles[ConsoleOutput] = ConsoleOutput;
    openFiles[ConsoleInput] = ConsoleInput;
    openFiles[ConsoleError] = ConsoleError;
    //marca ocupados los identificadores de console
    openFilesMap->Mark(ConsoleError);
    openFilesMap->Mark(ConsoleOutput);
    openFilesMap->Mark(ConsoleInput);
}

tablaControladoraArchivos::~tablaControladoraArchivos()
{
    cleanTable();
    delete [] openFiles;
}
void tablaControladoraArchivos::cleanTable(){
  for(int i = 3; i < MAX_FILES; ++i){
      if(openFilesMap->Test(i) && openFiles[i]!=-1){
          close(openFiles[i]);
          openFilesMap->Clear(i);
      }
  }
}
int tablaControladoraArchivos::Open(int UnixHandle)
{
    int k = 0;
    mutexLock->Acquire();

    bool encontrado = false;
    for(int i = 3; i < MAX_FILES && !encontrado; ++i){
        if(openFilesMap->Test(i) && openFiles[i] == UnixHandle)
        {
            k = i;
            encontrado = true;
        }
    }
    if(!encontrado){
      k = openFilesMap->Find();
      openFiles[k] = UnixHandle;
      DEBUG('F',"Open: UnixHandle: %i NachosHandle: %i\n",UnixHandle, k);
    }
    mutexLock->Release();

    return k;
}

int tablaControladoraArchivos::Close(int NachosHandle)
{
    int i;
    mutexLock->Acquire();

    if(NachosHandle >= MAX_FILES)
        i = -1;

    if( openFilesMap->Test(NachosHandle) ){
        openFilesMap->Clear(NachosHandle);
        i = openFiles[NachosHandle];
    }
    else{
      i=-1;
    }

    mutexLock->Release();
    return i;
}

bool tablaControladoraArchivos::isOpened(int NachosHandle) const
{
    mutexLock->Acquire();

    if(NachosHandle >= MAX_FILES)
        return false;

    mutexLock->Release();

    return openFilesMap->Test(NachosHandle);
}

int tablaControladoraArchivos::getUnixHandle(int NachosHandle) const
{
    mutexLock->Acquire();

    if(NachosHandle >= MAX_FILES || !openFilesMap->Test(NachosHandle) )
        return -1;

    mutexLock->Release();
    DEBUG('F',"getUnixHandle: UnixHandle: %i NachosHandle: %i\n",openFiles[NachosHandle], NachosHandle);
    return openFiles[NachosHandle];
}

void tablaControladoraArchivos::Print() const
{
    for(int i = 0; i < MAX_FILES; ++i){
        if(openFilesMap->Test(i))
            std::cout << i << " : " << openFiles[i] << std::endl;
        else
            std::cout << i << " : " << "no está en uso" << std::endl;
    }
}
