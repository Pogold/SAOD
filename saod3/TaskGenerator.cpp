#include "TaskGenerator.h"
#include<iostream>
#include"TaskGenerator.h"
#include <ctime>

Task* TaskGenerator::generateTask(int time) {
	int prior; // ���������
	int ta�t = time; // ����� ����������� 
	int dur; // ����� ����������

	string name = "������ # " + to_string(time);
	cout << name << endl;
	cout << "������� ��������� ������ [1-3]" << endl;
	cin >> prior;
	while (cin.fail() || prior < 1 || prior>3) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '/n');
		cout << "�������!" << endl;
		cout << "������� ��������� ������ [1-3]" << endl;
		cin >> prior;
	}
	cout << "������� ����������������� ������" << endl;
	cin >> dur;
	while (cin.fail() || dur < 1) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '/n');
		cout << "�������!" << endl;
		cout << "������� ����������������� ������" << endl;
		cin >> dur;
	}
	Task* task = new Task(name, prior, ta�t, dur);
	return task;

}
Task* TaskGenerator::autoGenerateTask(int timer) {
	srand(time(NULL));
	int prior; // ���������
	int ta�t = timer; // ����� ����������� 
	int dur; // ����� ����������
	string name = "������ # " + to_string(timer);
	prior = 1 + rand() % 3;
	dur = 1 + rand() % 5;
	cout << name << endl;
	cout << "��������� ������ " << prior << endl;
	cout << "����������������� ������ " << dur << endl;
	cout << "����� ����������� ������ " << ta�t << endl;
	Task* task = new Task(name, prior, ta�t, dur);
	return task;

}