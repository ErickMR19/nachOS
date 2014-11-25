// addrspace.cc
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include <cstdio>
#include <ctime>

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void
SwapHeader (NoffHeader *noffH)
{
    noffH->noffMagic = WordToHost(noffH->noffMagic);
	noffH->code.size = WordToHost(noffH->code.size);
	noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
	noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
	noffH->initData.size = WordToHost(noffH->initData.size);
	noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
	noffH->uninitData.size = WordToHost(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
    noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------

AddrSpace::AddrSpace(OpenFile *executable)
  :ejecutable(executable)
{
    unsigned int size;
    unsigned int i;
    ejecutable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && (WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);

    ASSERT(noffH.noffMagic == NOFFMAGIC);

    //printf("noffMagic: %i NOFFMAGIC: %i\n",noff);

    // how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size
			+ UserStackSize;	// we need to increase the size
						// to leave room for the stack
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;
    DEBUG('d', "Initializing address space, num pages %d, size %d\n", numPages, size);


    #ifndef VM //estas verficicaciones no tienen sentido cuando se trabaja con memoria virtual
    ASSERT(numPages <= NumPhysPages);		// check we're not trying
						// to run anything too big --
						// at least until we have
                        // virtual memorys


  	// first, set up the translation
  	 ASSERT(numPages <= MapaMemoria.NumClear());
    #endif


  pageTable = new TranslationEntry[numPages];
	int indice = 0;
	for (i = 0; i < numPages; i++){
    	// busca una posición libre
        ASSERT(indice != -1);
    		pageTable[i].virtualPage = i;

    		#ifdef VM
    			pageTable[i].valid = false;
          pageTable[i].physicalPage = -1; //páginas invalidas
    		#else
          indice = MapaMemoria.Find();
    			pageTable[i].valid = true;
          pageTable[i].physicalPage = indice;
    		#endif

    		pageTable[i].use = false;
    		pageTable[i].dirty = false;
    		pageTable[i].readOnly = false;  // if the code segment was entirely on
    						// a separate page, we could set its
    						// pages to be read-only
            //printf("Asigno la: %u\n",indice);
    }

// zero out the entire address space, to zero the unitialized data segment
// and the stack segment

	// copia el segmento de codigo desde el archivo
    paginasCodigo = divRoundUp(noffH.code.size, PageSize);
    DEBUG('d', "paginasCodigo: %i \n",paginasCodigo);
    paginasCodigo = divRoundUp(noffH.code.size, PageSize);
    int paginasDatos = divRoundUp(noffH.initData.size, PageSize);
    DEBUG('d', "paginasDatos: %i \n",paginasDatos);
    numeroPaginasInicializadas = paginasCodigo + paginasDatos;
    #ifndef VM
  	i = 0;
  	int paginaMemoria;
      if (noffH.code.size > 0) {
      	for(i=0; i < paginasCodigo; ++i){
      		paginaMemoria = pageTable[i].physicalPage;
  		DEBUG('d', "code... i(%i) pm(%i)\n",i,paginaMemoria);
  	        executable->ReadAt(&(machine->mainMemory[paginaMemoria*PageSize]),
  				PageSize, noffH.code.inFileAddr+i*PageSize);
      	}
      }
    // copia el segmento de datos desde el archivo
    DEBUG('d', "paginasDatos: %i \n",paginasDatos);
  	if (noffH.initData.size > 0) {
      	for(i=0; i < paginasDatos; ++i){
      		paginaMemoria = pageTable[i+paginasCodigo].physicalPage;
  		DEBUG('d', "datos... i(%i) pm(%i)\n",i,paginaMemoria);
  	        executable->ReadAt(&(machine->mainMemory[paginaMemoria*PageSize]),
  				PageSize, noffH.initData.inFileAddr+i*PageSize);
      	}
      }

    #endif

    // segmento de pila
	int paginasPila = divRoundUp(UserStackSize, PageSize);
            DEBUG('d', "paginasPila: %i \n",paginasPila);



        DEBUG('d', "Termino el costructor\n");
}

AddrSpace::AddrSpace(AddrSpace *addrSpace)
: ejecutable(NULL)
{
	int paginasPila = divRoundUp(UserStackSize, PageSize);
	numPages = addrSpace->numPages;
	ASSERT(paginasPila <= MapaMemoria.NumClear());
	pageTable = new TranslationEntry[numPages];
	int paginasEnComun = numPages-paginasPila;

	int indice, i;
	// copia los indices del addrSpace enviado por parametro,para compartir así datos y código
	for (i = 0; i < paginasEnComun; i++) {
		pageTable[i].virtualPage = addrSpace->pageTable[i].virtualPage;
		pageTable[i].physicalPage = addrSpace->pageTable[i].physicalPage;
		pageTable[i].valid = true;
		pageTable[i].use = false;
		pageTable[i].dirty = false;
		pageTable[i].readOnly = false;
	}
	// asigna e inicializa un nuevo segmento de pila
	for(i = paginasEnComun; i < paginasPila+paginasEnComun; ++i){
    	// busca una posición libre
        indice = MapaMemoria.Find();
        ASSERT(indice != -1);
		pageTable[i].virtualPage = indice;	// for now, virtual page # = phys page #
		pageTable[i].physicalPage = indice;
		pageTable[i].valid = true;
		pageTable[i].use = false;
		pageTable[i].dirty = false;
		pageTable[i].readOnly = false;  // if the code segment was entirely on
						// a separate page, we could set its
						// pages to be read-only
        //printf("Asigno la: %u\n",i);
    }
}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{
	for(unsigned i = 0; i < numPages; ++i){
		MapaMemoria.Clear(pageTable[i].physicalPage);
	}
	delete pageTable;
  if(ejecutable)
    delete ejecutable;
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
AddrSpace::InitRegisters()
{
    unsigned i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void AddrSpace::SaveState()
{}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState()
{
	#ifndef VM
	machine->pageTable = pageTable;
	machine->pageTableSize = numPages;
	#endif
}

#ifdef VM
int AddrSpace::escogerPaginaDelTLB(){
    srand( time(NULL) );
    bool buscando = true;
    int i;
    for(i = 0; i < TLBSize; ++i){
      if(! machine->tlb[i].valid ){ // si hay alguna sin usar, utilizar esa
        DEBUG('P',"se asigna pagina sin usar %i\n",i);
        return i;
      }
    }
    for(i = 0; i < TLBSize; ++i){
      if(! machine->tlb[i].dirty ){ // si hay alguna sin que no este "dirty", usar esa
        DEBUG('P',"se asigna pagina usada pero limpia %i\n",i);
        return i;
      }
    }
    i = rand() % TLBSize;
    DEBUG('P',"asigna una pagina aleatoria, ya que todas estan sucias %i\n",i);
    pageTable[ machine->tlb[i].virtualPage ].dirty = true; // indico que la pagina que se va a quitar del TLB estaba "dirty"
    return i;
}
void AddrSpace::copiarAlTLB(int pagPageTable, int pagTLB){
  DEBUG('P',"se copia en la pagina %i del TLB, la pagina %i del pageTable\n",pagTLB,pagPageTable);
  machine->tlb[pagTLB].virtualPage = pageTable[pagPageTable].virtualPage;
  machine->tlb[pagTLB].physicalPage = pageTable[pagPageTable].physicalPage;
  machine->tlb[pagTLB].dirty = pageTable[pagPageTable].dirty;
  machine->tlb[pagTLB].valid = true;
  machine->tlb[pagTLB].use = true;
}
int ultimaPosicionAsignada=-1;

int AddrSpace::encontrarPosicionDeMemoria(){
  int indice = MapaMemoria.Find();
  DEBUG('P',"encontrar memoria devolvio %i\n",indice);
  if (indice == -1){ // si el indice es -1 no hay espacio disponible
    DEBUG('P',"indice -1, debe usarse SecondChance\n");
    //inicio SecondChance
      int encontrado = false;
      indice = ultimaPosicionAsignada;
      DEBUG('P',"al indice se asigna la ultima posicion asignada: %i\n",indice);
      while(! encontrado){
        ++indice;
        if( tpi[indice%NumPhysPages].use ){
          DEBUG('P',"indice -1, debe usarse SecondChance\n");
          tpi[indice%NumPhysPages].use = false;
        }
        else{
          encontrado = true;
          indice = indice%NumPhysPages;
          if( pageTable[ tpi[indice].virtualPage ].dirty ){
            //TODO: copiarAlSWAP( tpi[indice].virtualPage );
          }
          pageTable[ tpi[indice].virtualPage ].physicalPage = -1;
          pageTable[ tpi[indice].virtualPage ].valid = false;
          pageTable[ tpi[indice].virtualPage ].use = false;
        }
      }
  }
  tpi[indice].use = true;
  ultimaPosicionAsignada = indice;
  return indice;
}
void AddrSpace::actualizarTLB(int paginaFaltante){
    int paginaTLB = escogerPaginaDelTLB();
    DEBUG('P',"se va a actualizar la pagina %i del TLB, con la pagina %i del pageTable\n",paginaTLB,paginaFaltante);
    copiarAlTLB(paginaFaltante,paginaTLB);
}
void AddrSpace::CargarDespuesDePFException(int addressPageFault)
{
    unsigned int paginaFaltante = addressPageFault / PageSize;
    DEBUG('P',"Pagina Faltante: %u\n",paginaFaltante);
    if(pageTable[paginaFaltante].valid){ // está en memoria
      DEBUG('P',"La pagina es valida, es decir esta en memoria\n");
    }
    else{ // no está en memoria
      int posicionDeMemoria = encontrarPosicionDeMemoria();
      pageTable[paginaFaltante].physicalPage = posicionDeMemoria;
      DEBUG('P',"La pagina no estaba cargada en memoria, se va a cargar en la posicion: %i \n",posicionDeMemoria);
      if(pageTable[paginaFaltante].dirty){ // la pagina de datos no inicializados y está sucia
        DEBUG('P',"La pagina estaba sucia, se debe cargar del swap\n");
        //TODO: cargar del SWAP
      }
      else {
        if(paginaFaltante < numeroPaginasInicializadas){ // pagina de datos inicializados
          DEBUG('P',"La pagina se debe leer del ejecutable\n");
          if (paginaFaltante < paginasCodigo) { //verifica si es el del segmento de codigo
              DEBUG('P',"La pagina es de codigo\n");
              ejecutable->ReadAt(&(machine->mainMemory[posicionDeMemoria*PageSize]),
                                 PageSize,
                                 noffH.code.inFileAddr+paginaFaltante*PageSize
                                 );
          }
          else{ // es del segmento de datos inicializados
              DEBUG('P',"La pagina es de datos inicializados\n");
              ejecutable->ReadAt(&(machine->mainMemory[posicionDeMemoria*PageSize]),
                                 PageSize,
                                 noffH.initData.inFileAddr+(paginaFaltante-paginasCodigo)*PageSize
                                 );
          }
        }
        else{ // pagina de datos no inicializados y no está sucia
          DEBUG('P',"La pagina es de pila\n");
          bzero(&(machine->mainMemory[posicionDeMemoria * PageSize]), PageSize);
          pageTable[paginaFaltante].physicalPage = posicionDeMemoria;
          pageTable[paginaFaltante].valid = true;
          pageTable[paginaFaltante].use = true;
        }
      }
    }
/*
    if(pageTable[paginaFaltante].valid == false && pageTable[paginaFaltante].dirty == true)
    {
        OpenFile* workingSwap = fileSystem->Open("SWAP");
        int initialFind = mybit->Find();
        workingSwap->ReadAt(&(machine->mainMemory[PageSize * paginaFaltante]), PageSize * initialFind);

        pageTable[paginaFaltante].valid = true;
        pageTable[paginaFaltante].physicalPage = initialFind;
        coreMap[initialFind].virtualPage = paginaFaltante;
    }*/
   actualizarTLB(paginaFaltante);
}
#endif
