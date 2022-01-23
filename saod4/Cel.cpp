#include "Cel.h"

Cell::Cell() //конструктор списка
{
    Size = 0;
    head = nullptr;
}

//деструктор списка
Cell::~Cell()
{
    clear();
}

void Cell::pop_front()
{
    Node* temp = head; //временная нода для удаления (записываем в переменную изначальную голову)
    head = head->pNext;//теперь голова следующий элемент от старой головы
    delete temp; //удалить старую голову
    Size--; //уменишаем размер списка на один так как удаляем голову

}

void Cell::push_back(string data) //добавление элемента в конец списка
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else {
        Node* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

void Cell::clear()
{
    while (Size)// когда число равно 0=false (так как в вайле булевая переменная) в остальных случаях (!-=0) тру
    {
        pop_front();
    }
}

string& Cell::operator[](const int index) //поиск элемента
{
    int counter = 0;
    Node* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

bool Cell::hashexist(string key)
{
    Node* cur = this->head; //временный указатель

    for (int i = 0; i < Size; i++)
    {
        if (cur->data == key)
        {
            return true;
        }
        cur = cur->pNext;

    }

    return false;
}

bool Cell::removeAt(string key) //удаление элемента по индексу
{
    Node* previous = this->head; //временный указатель
    if ((previous->data == key))
    {
        pop_front();
        return true;
    }
    else {
        for (int i = 0; i <= Size - 1; i++)// находим адрес предыдущего элемента от которого хотим заменить
        {
            if (previous->data == key)
            {
                Node* toDelete = previous->pNext;
                if (previous->pNext != nullptr) {
                    previous->pNext = toDelete->pNext;
                }
                delete toDelete;
                Size--;
                return true;
            }
            previous = previous->pNext;
        }
    }
    return false;
}

void Cell::ShowCell()
{
    Node* current = this->head; //временный указатель

    if (Size != 0) {
        for (int i = 0; i < Size; i++)// находим адрес предыдущего элемента от которого хотим заменить
        {
            cout << i << ": " << current->data << "  ";
            current = current->pNext;
        }
    }
    else { cout << "Пусто" << endl; }
}