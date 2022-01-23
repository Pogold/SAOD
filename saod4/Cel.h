#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cell
{
public:
    Cell();
    ~Cell();

    void pop_front();//�������� �������  �������� 
    void push_back(string data); //���������� �������� � ����� ������
    int GetSize() { return Size; }; //���������� ���-�� ���������  � ������
    void clear();//������� ������
    string& operator[] (const int index);//����� ��������
    bool removeAt(string key);//�������� �������� �� �������
    void ShowCell();
    bool hashexist(string key);

private:
    class Node // ����� ����
    {
    public:
        Node* pNext;//��������� �� ��������� ����
        string data; //�������� ����

        Node(string data, Node* pNext = nullptr) // ����������� ���� ���������� �������� � ������
        {
            this->data = data;
            this->pNext = pNext;
        };

    };

    int Size;
    Node* head; //������ ������ ������ �������
};

