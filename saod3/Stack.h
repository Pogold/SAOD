#pragma once
#include"Task.h"
using namespace std;
class Stack {

public:
	Stack();
	~Stack();
	void clear();
	void pop_front();		//метод для удаление первого элементы списка
	void push_front(Task data);			// добавление в начало списка
	int GetSize() { return Size; }
	Task* taskreturn();
	Task& operator[](const int index);
	void printStack();
private:


	class Node {
	public:
		Node* pNext;
		Task data;

		Node(Task data = Task(), Node* pNext = nullptr) {		// конструктор узла
			this->data = data;
			this->pNext = pNext;
		}
	};
  public:

	int Size;
	Node* head;


};
