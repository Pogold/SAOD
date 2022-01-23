#pragma once
#include <string>
#include <iostream>
using namespace std;
class Task
{
public:
    void setname(string n);
    void setprior(int p);
    void settact(int t);
    void  setdur(int d);
    string getname();
    int getprior();
    int gettact();
    int  getdur();
    Task();
    Task(string n, int p, int t, int d);

private:
    string name; // имя
    int prior; //приоритет
    int tact; // время поступления
    int dur;  // длительность выполнения

};


