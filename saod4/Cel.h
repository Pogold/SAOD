#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cell
{
public:
    Cell();
    ~Cell();

    void pop_front();//удаление первого  элемента 
    void push_back(string data); //добавление элемента в конец списка
    int GetSize() { return Size; }; //нахождение кол-ва элементов  в списке
    void clear();//очистка списка
    string& operator[] (const int index);//поиск элемента
    bool removeAt(string key);//удаление элемента по индексу
    void ShowCell();
    bool hashexist(string key);

private:
    class Node // класс узла
    {
    public:
        Node* pNext;//указатель на следующий узел
        string data; //значение узла

        Node(string data, Node* pNext = nullptr) // конструктор ноды присваение значения и адреса
        {
            this->data = data;
            this->pNext = pNext;
        };

    };

    int Size;
    Node* head; //голова списка первый элемент
};

