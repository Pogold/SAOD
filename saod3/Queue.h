#pragma once
#include "Task.h"

class Queue
{

public:
	Queue();
	~Queue();
	void push_back(Task value);
	int getSize() const;
	Task& operator[] (int);
	void popFront();
	void clear();
	void printQueue(Queue Q);

private:
	class Node
	{
	public:
		Task data;
		Node* next;

		Node(Task t = Task(), Node* n = nullptr);
	};
public:
	Node* head;
	int size;
};