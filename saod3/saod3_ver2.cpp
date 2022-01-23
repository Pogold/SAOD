#include <iostream>
#include "Queue.h"
#include "TaskGenerator.h"
#include "Task.h"
#include "Stack.h"
#include "Processor.h"
#include <locale.h>
#include <Windows.h>

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian"); //подключаем русский язык

    Stack S; //стэк
    Queue F1,F2,F3;//очереди
    Processor P;//процессор
    TaskGenerator TG;// таскгенератор
    int timer = 1;// такт
    int choice = 0; // выбор

    Task temp1; //временный таск
    Task* temp = &temp1;

    do  
     {
        cout << "Такт №" << timer << endl;

        //if ((F1.getSize() > 10) || (F2.getSize() > 10) || (F3.getSize() > 10) || (S.GetSize() > 10))  //если хотя бы одна из структур имеет больше 10 элементов 
        //{ 
        //    cout << "Переполнение!" << endl;
        //    choice = 3;
        //}else {
        cout << "Как вы хотите создать задачу:" << endl;
        cout << "1.Вручную" << endl;
        cout << "2.Рандомно" << endl;
        cout << "3.Пропуск такта" << endl;
        cout << "4.Выход" << endl;
        cin >> choice;
        cout << endl;
       // }

        if (choice != 3) //если не пропускаем такт
        {
        if (choice == 1) {temp = TG.generateTask(timer);}
        else if (choice == 2) { temp = TG.autoGenerateTask(timer);}


        if ((*temp).getprior() == 1) {F1.push_back(*temp); } //добавляем задачу в зависимости от приоритета

        else if ((*temp).getprior() == 2) {F2.push_back(*temp);}

        else if((*temp).getprior()==3){ F3.push_back(*temp); }
        }

        cout  << endl;
        cout << "======= Содержимое структур=======" << endl;
        cout  << endl;

       cout << "======= F1 =======" << endl;//вывод очереди F1
       if (F1.getSize() == 0) {
           cout << "Пусто" << endl;
           cout << endl;
           }
        else {
        for (int i = 0; i < F1.getSize(); i++) {
            cout << "Имя задачи:" << F1[i].getname() << endl;
            cout << "Приоритет:" << F1[i].getprior() << endl;
            cout << "Время поступления:" << F1[i].gettact() << endl;
            cout << "Длительность выполнения:" << F1[i].getdur() << endl;
            cout << endl;

        }
        }
        cout << "======= F2 =======" << endl;//вывод очереди F2
        if(F2.getSize()==0){
            cout << "Пусто"  << endl;
            cout << endl; } 
        else {
        for (int i = 0; i < F2.getSize(); i++) {
            cout << "Имя задачи:" << F2[i].getname() << endl;
            cout << "Приоритет:" << F2[i].getprior() << endl;
            cout << "Время поступления:" << F2[i].gettact() << endl;
            cout << "Длительность выполнения:" << F2[i].getdur() << endl;
            cout << endl; }
        }

        cout << "======= F3 =======" << endl;  //вывод очереди  F3
        if (F3.getSize() == 0) {
            cout << "Пусто" << endl;
            cout << endl; }
        else {
        for (int i = 0; i < F3.getSize(); i++) {
            cout << "Имя задачи:" << F3[i].getname() << endl;
            cout << "Приоритет:" << F3[i].getprior() << endl;
            cout << "Время поступления:" << F3[i].gettact() << endl;
            cout << "Длительность выполнения:" << F3[i].getdur() << endl;
            cout << endl; }
        }

        cout << "======= Состояние Процессора =======" << endl;


        if (P.Procisempty() == true) //если добавляется задача с большим приоритетом чем в процессоре
        {
            if ( (P.getprior() != 0) && (F1.getSize() != 0) && (P.getprior() > 1)) // если задача в проце ниже по приоритету чем в очереди то меняем (очередь не пуста и проц тоже)
            {
                S.push_front(P.getTaskproc()); // отправляем задачу в стэк
                P.kill(&F1.head->data, timer);//заменить задачу с высшим приоритетом 
                F3.popFront();
            }
            else if ( (P.getprior() != 0) && (F2.getSize() != 0) && (P.getprior() > 2) )
            {
                S.push_front(P.getTaskproc()); // отправляем задачу в стэк
                P.kill(&F2.head->data, timer);//заменить задачу с высшим приоритетом 
                F3.popFront();
            }
        }
        else if (P.Procisempty() == false) {
            if (F1.getSize() != 0) //когда f1 не пуста
            {
                *temp = F1.head->data;
                P.getTask(temp, timer);//добавить таск в процессор
                F1.popFront();//удалить таск из очереди
            }
            else if (F2.getSize() != 0) //когда f2 не пуста
            {
                *temp = F2.head->data;
                P.getTask(temp, timer);//добавить таск в процессор
                F2.popFront();//удалить таск из очереди
            }
            else if (F3.getSize() != 0) //когда f3 не пуста
            {
                *temp = F3.head->data;
                P.getTask(temp, timer);//добавить таск в процессор
                F3.popFront();//удалить таск из очереди
            }

           
            if ((F1.getSize() == 0) && (F2.getSize() == 0) && (F3.getSize() == 0) && (P.Procisempty() == false) && (S.GetSize() != 0)) //когда все очереди пусты и стэк непуст
            {
                P.getTask(&S.head->data, timer); //добавить таск в процессор
                S.pop_front();//удалить таск из стэка
            }
        }

        P.Working(); //работа процессора
        P.PrintProc(); //вывод процессора

        cout << "======= Стэк =======" << endl;
        if (S.GetSize() == 0) {
            cout << "Пусто" << endl;
            cout << endl;
        }
        else {
            for (int i = 0; i < S.GetSize(); i++) {
                cout << "Имя задачи:" << S[i].getname() << endl;
                cout << "Приоритет:" << S[i].getprior() << endl;
                cout << "Время поступления:" << S[i].gettact() << endl;
                cout << "Длительность выполнения:" << S[i].getdur() << endl;
                cout << endl;
            }
        }

        timer++; //переход на следующий такт
        cout << "=======================================================" << endl;
        cout << endl;
        cout << endl;

    } while (choice!=4);
    


  return 0;

}

