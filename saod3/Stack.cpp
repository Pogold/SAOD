#include "Stack.h"


Stack::Stack() {                       //�����������
	Size = 0;
	head = nullptr;
}

Stack::~Stack() {						//����������
	clear();
}

void Stack::clear() {
	while (Size) {
		pop_front();
	}
}


void Stack::pop_front() {
	Node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}


void Stack::push_front(Task data) {
	head = new Node(data, head);
	Size++;
}


Task* Stack::taskreturn()
{
	Node* current = this->head;
	Task T1;
	T1 = current->data;
	Task* T = &T1; 

	return T;
}

Task& Stack::operator[](const int index) {
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

	Size++;
}

void Stack::printStack()
{
	Node* current = this->head;
	for (int i = 0; i < Size; i++)
	{
		cout << "��� ������:" << current[i].data.getname() << endl;
		cout << "���������:" << current[i].data.getprior() << endl;
		cout << "����� �����������:" << current[i].data.gettact() << endl;
		cout << "������������ ����������:" << current[i].data.getdur() << endl;
		cout << endl;
	}


}