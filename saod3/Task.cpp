#include "Task.h"

////////////////////////////////TASK//////////////////////////////////////////

void Task::setname(string n)
{
    name = n;
}

void Task::setprior(int p)
{
    prior = p;
}

void Task::settact(int t)
{
    tact = t;
}

void Task::setdur(int d)
{
    dur = d;
}

string Task::getname()
{
    return name;
}

int Task::getprior()
{
    return prior;
}

int Task::gettact()
{
    return tact;
}

int Task::getdur()
{
    return dur;
}

Task::Task()
{
    name ="0";
    dur = 0;
    tact = 0;
    prior = 0;
}

Task::Task(string n, int p, int t, int d)
{
    name = n;
    dur = d;
    tact = t;
    prior = p;
}