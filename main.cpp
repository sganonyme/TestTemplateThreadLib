//============================================================================
// Name        : TemplateThreadCom.cpp
// Author      : SG
// Version     :
// Copyright   : Your copyright notice
// Description : Template Thread Com
//============================================================================

#include "clavier.hpp"
#include "screen.hpp"
#include "task1.hpp"
#include "task2.hpp"
#include "com.hpp"

int main(int argc, char *argv[])
    {
    char car;

    // Initialisation task Principal
    TThread::initTaskMain();

    // Création Clavier et console
    TClavier *clavier = TClavier::getInstance();
    TScreen *screen  = new TScreen();
    screen->start();

    // Création tâches
    TTask1 *task1 = new TTask1("Task 1",screen,SCHED_RR,80);
    TTask2 *task2 = new TTask2("Task 2",screen,SCHED_RR,79);

    // Démarrage tâches
    task1->start();
    task2->start();

    // Traitement tâche principale
    screen->dispStr(1,1,"Test Com (SG  27/08/2020)");
    do
      {
      // Traitement

      if(clavier->kbhit())
		  {
		  car = clavier->getch();
		  }
      }
    while( (car != 'q') && (car != 'Q') );

    // Destruction tâches
    if(task1)
    	delete task1;
    if(task2)
		delete task2;

    // Destruction console
    if(screen)
    	delete screen;

    return 0;
    }
