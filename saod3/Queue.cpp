#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Node::Node(Task t, Node* n)
{
	data = t;
	next = n;
}


Queue::Queue()
{
	size = 0;
	head = nullptr;
}


Queue::~Queue()
{
	clear();
}


void Queue::push_back(Task value)
{
	if (head == nullptr)
		head = new Node(value);
	else
	{
		for (Node* current = head; ; current = current->next)
			if (current->next == nullptr)
			{
				current->next = new Node(value);
				break;
			}
	}
	size++;
}


int Queue::getSize() const
{
	return size;
}


Task& Queue::operator[](int index)
{
	if (index > size - 1 || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	Node* current = head;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->data;
}


void Queue::popFront()
{
	if (size <= 0) return;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}



void Queue::clear()
{
	while (size) popFront();
}



void Queue::printQueue(Queue Q)
{

	for (int i = 0; i < Q.getSize(); i++)
	{
		cout << "Имя задачи:" << Q[i].getname() << endl;
		cout << "Приоритет:" << Q[i].getprior() << endl;
		cout << "Время поступления:" << Q[i].gettact() << endl;
		cout << "Длительность выполнения:" << Q[i].getdur() << endl;
		cout << endl;
	}
}
	

