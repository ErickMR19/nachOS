#include "tablaindicadores.h"
#include <iostream>
#include <unistd.h>
#include "scheduler.h"
extern Thread* currentThread;
extern Scheduler *scheduler;
tablaIndicadoresProcesos::tablaIndicadoresProcesos():
processesMutexLock("Mutex for proctable"),
runningProcessesMap(MAX_PROCESS)
{
	usage = 0;
	runningProcesses = new Process[MAX_PROCESS];
}

tablaIndicadoresProcesos::~tablaIndicadoresProcesos()
{
  delete[] runningProcesses;
}


int tablaIndicadoresProcesos::RegisterProcess( Thread* hilo	)
{
	processesMutexLock.Acquire();
	int id;
	bool esta =false;
	for(int i = 0; i < MAX_PROCESS && !esta; ++i){
		if(runningProcessesMap.Test(i) && runningProcesses[i].thread == hilo){
			esta = true;
			id = i;
		}
	}
	if(!esta){
		id = runningProcessesMap.Find();
		runningProcesses[id].thread = hilo;
		runningProcesses[id].pid = id;
		runningProcesses[id].parentPid = -1; // no tiene padre
		runningProcesses[id].exitStatus = NULL;
	}
	processesMutexLock.Release();

	return id;
}

tablaControladoraArchivos* tablaIndicadoresProcesos::getTablaArchivos(int pid){
	bool esta = false;
	processesMutexLock.Acquire();
	esta = isRegistered(pid);
	processesMutexLock.Release();
	if(!esta)
		return NULL;
	return runningProcesses[pid].tablaArchivos;
}

tablaControladoraArchivos* tablaIndicadoresProcesos::getTablaArchivos(Thread* hilo){
	processesMutexLock.Acquire();
	int id;
	bool esta =false;
	for(int i = 0; i < MAX_PROCESS && !esta; ++i){
		if(runningProcessesMap.Test(i) && runningProcesses[i].thread == hilo){
			esta = true;
			id = i;

		}
	}
	if(!esta){

		id = runningProcessesMap.Find();
		runningProcesses[id].thread = hilo;
		runningProcesses[id].pid = id;
		runningProcesses[id].parentPid = -1; // no tiene padre
		runningProcesses[id].exitStatus = NULL;
	}
	processesMutexLock.Release();
	return runningProcesses[id].tablaArchivos;
}

int tablaIndicadoresProcesos::RegisterProcess(Thread* hilo, int parentPid)
{
	processesMutexLock.Acquire();
	int id;
	bool esta =false;
	for(int i = 0; i < MAX_PROCESS && !esta; ++i){
		if(runningProcessesMap.Test(i) && runningProcesses[i].thread == hilo){
			esta = true;
			id = i;
		}
	}

	if(!esta){
		id = runningProcessesMap.Find();
		ASSERT(id != -1);
		runningProcesses[id].thread = hilo;
		runningProcesses[id].pid = id;
		runningProcesses[id].parentPid = parentPid;
		runningProcesses[id].exitStatus = NULL;
	}
	processesMutexLock.Release();

	return id;
}

void tablaIndicadoresProcesos::DeRegisterProcess(int pid, int exitStatus)
{
	processesMutexLock.Acquire();

	if( runningProcessesMap.Test(pid) ){
		runningProcesses[pid].exitStatus = new int(exitStatus);
		runningProcessesMap.Clear(pid);
		--usage;
	}Thread* temp;
	while ( ! runningProcesses[pid].waiting.IsEmpty() )
	{		temp =runningProcesses[ runningProcesses[pid].waiting.Remove() ].thread;
		  DEBUG('t',"%s va a despertar a: %s\n", currentThread->getName(),temp->getName());
	    scheduler->ReadyToRun(temp);
	}

	//currentThread->Yield();
	processesMutexLock.Release();
}

void tablaIndicadoresProcesos::setStatus(int pid,int i){
	processesMutexLock.Acquire();

	processesMutexLock.Release();

}

int tablaIndicadoresProcesos::Join(int pid){
	DEBUG('t',"voy a dormir\n" );
	runningProcesses[pid].waiting.Append( RegisterProcess(currentThread) );
	currentThread->setStatus(BLOCKED);

	scheduler->Run(scheduler->FindNextToRun());
	DEBUG('t',"ya desperte\n" );
	return *(runningProcesses[pid].exitStatus);
}

bool tablaIndicadoresProcesos::isRegistered(int pid)
{
	return (runningProcessesMap.Test(pid));
}

Thread* tablaIndicadoresProcesos::getThread(int pid) const
{
	return runningProcesses[pid].thread;
}

void tablaIndicadoresProcesos::cleanTable()
{
	for (int i = 0; i < 120; ++i)
	{
		runningProcessesMap.Clear(i);
	}
}

bool tablaIndicadoresProcesos::IsIncluded(Thread* hilo)
{
	for (int i = 0; i < MAX_PROCESS; ++i)
	{
		if (runningProcesses[i].thread == hilo)
		 {
		 	return true;
		 }
	}
	return false;
}

void tablaIndicadoresProcesos::Print()
{
	for (int i = 0; i < MAX_PROCESS; ++i)
	{
		if ( runningProcessesMap.Test(i) )
		{
			printf("%i : %s\n",i,runningProcesses[i].thread->getName());
		}
		else{
			printf("%i : --\n",i);
		}
	}
}
