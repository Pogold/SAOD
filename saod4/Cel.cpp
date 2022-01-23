#include "Cel.h"

Cell::Cell() //����������� ������
{
    Size = 0;
    head = nullptr;
}

//���������� ������
Cell::~Cell()
{
    clear();
}

void Cell::pop_front()
{
    Node* temp = head; //��������� ���� ��� �������� (���������� � ���������� ����������� ������)
    head = head->pNext;//������ ������ ��������� ������� �� ������ ������
    delete temp; //������� ������ ������
    Size--; //��������� ������ ������ �� ���� ��� ��� ������� ������

}

void Cell::push_back(string data) //���������� �������� � ����� ������
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
    while (Size)// ����� ����� ����� 0=false (��� ��� � ����� ������� ����������) � ��������� ������� (!-=0) ���
    {
        pop_front();
    }
}

string& Cell::operator[](const int index) //����� ��������
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
    Node* cur = this->head; //��������� ���������

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

bool Cell::removeAt(string key) //�������� �������� �� �������
{
    Node* previous = this->head; //��������� ���������
    if ((previous->data == key))
    {
        pop_front();
        return true;
    }
    else {
        for (int i = 0; i <= Size - 1; i++)// ������� ����� ����������� �������� �� �������� ����� ��������
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
    Node* current = this->head; //��������� ���������

    if (Size != 0) {
        for (int i = 0; i < Size; i++)// ������� ����� ����������� �������� �� �������� ����� ��������
        {
            cout << i << ": " << current->data << "  ";
            current = current->pNext;
        }
    }
    else { cout << "�����" << endl; }
}