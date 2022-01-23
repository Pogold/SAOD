#pragma once
#include "Cel.h"
#include <string>
#include <iostream>
#include <regex>
using namespace std;

class HashTable
{
public:
    HashTable();
    ~HashTable();
    Cell* arr;

    void add(string key);
    void find();
    void Print();
    void del();
    int GetSize() { return size; }; //нахождение кол-ва элементов  в списке
    string inputKey();
    int inputNum();
    int HashFunctionHorner(const string& s, int table_size, const int key);
private:
    static const int default_size = 1500;
    int size; // сколько элементов у нас сейчас в массиве 
};


