#include "task2.hpp"

TTask2::TTask2(const char *name,void *shared,int policy,int priority) :
                                                           TThread(name,shared,policy,priority)
    {
	screen = (TScreen *)shared;

    screen->dispStr(1,4,"Task 2 :");
    }

TTask2::~TTask2()
    {
    }

void TTask2::task(void)
    {
    // variable locale
    char strCar[2] = {'-','\0'};

    // synchronisation démarrage tâche
    signalStart();

    while(1)
		{
		//traitement
		if(strCar[0] == '|')
			strCar[0] = '-';
		else
			strCar[0] = '|';
		screen->dispStr(10,4,strCar);

		sleep(1);   // 1s
		}
    }
