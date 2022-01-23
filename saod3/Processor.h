#pragma once
#include "Task.h"
#include "Stack.h"

class Processor
{
private:
	int duration= 0;
	int timer = 0;
	bool work = false;
	Task task_processor;
public:
	void kill(Task* T, int time);
	int getprior();
	Task getTaskproc();
	void getTask(Task* T, int timer);
	bool Working();
	bool Procisempty();
	void PrintProc();
};

