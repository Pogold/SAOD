#pragma once
#include"Task.h"
using namespace std;
class Stack {

public:
	Stack();
	~Stack();
	void clear();
	void pop_front();		//����� ��� �������� ������� �������� ������
	void push_front(Task data);			// ���������� � ������ ������
	int GetSize() { return Size; }
	Task* taskreturn();
	Task& operator[](const int index);
	void printStack();
private:


	class Node {
	public:
		Node* pNext;
		Task data;

		Node(Task data = Task(), Node* pNext = nullptr) {		// ����������� ����
			this->data = data;
			this->pNext = pNext;
		}
	};
  public:

	int Size;
	Node* head;


};
