#include "Processor.h"
#include <iostream>

void Processor::kill(Task* T, int time)
{
    task_processor.setdur(0);    // �������� ������ � ����������
    task_processor.setprior(0);
    task_processor.setname("0");
    task_processor.settact(0);

    getTask(T, time);  // ��������� ������ � ����������
}

int Processor::getprior()
{
    return task_processor.getprior();
}

Task Processor::getTaskproc()
{
    return task_processor;
}

void Processor::getTask(Task* T,int time)
{
    task_processor.setdur(T->getdur());
    task_processor.setprior(T->getprior());
    task_processor.setname(T->getname());
    task_processor.settact(T->gettact());

    duration = task_processor.getdur();
    timer = time;
    work = true;
}

bool Processor::Working()
{
   if((task_processor.getname()!="0") || (task_processor.getprior()!=0))
   {

    duration--;
    if (duration!=0){
    cout << "������ ����� ����������� " << duration << " �����" <<endl;
    }
   }

    if (duration == 0)
    {
        work = false;
        task_processor.setdur(0);
        task_processor.setprior(0);
        task_processor.setname("0");
        task_processor.settact(0);
        cout << "������ ��������� ��� �� ��������� " << endl;
    }
    else {
        work = true;
        cout << "��������� � ������" << endl;
    }

    return work;
}


bool Processor::Procisempty()
{
     return work;
}

void Processor::PrintProc()
{
    cout << endl;
    cout << "=======���������=======" << endl;
   if (task_processor.getname() !="0")
   { 
    cout << "��� ������:" << task_processor.getname() << endl;
    cout << "���������:" << task_processor.getprior() << endl;
    cout << "����� �����������:" << task_processor.gettact() << endl;
    cout << "������������ ����������:" << task_processor.getdur() << endl;
    cout << endl;
   } else { cout << "�����" << endl; }
}
