#include "TaskGenerator.h"
#include<iostream>
#include"TaskGenerator.h"
#include <ctime>

Task* TaskGenerator::generateTask(int time) {
	int prior; // приоритет
	int taсt = time; // время поступления 
	int dur; // время выполнения

	string name = "Задача # " + to_string(time);
	cout << name << endl;
	cout << "Введите приоритет задачи [1-3]" << endl;
	cin >> prior;
	while (cin.fail() || prior < 1 || prior>3) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '/n');
		cout << "Неверно!" << endl;
		cout << "Введите приоритет задачи [1-3]" << endl;
		cin >> prior;
	}
	cout << "Введите продолжительность задачи" << endl;
	cin >> dur;
	while (cin.fail() || dur < 1) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '/n');
		cout << "Неверно!" << endl;
		cout << "Введите продолжительность задачи" << endl;
		cin >> dur;
	}
	Task* task = new Task(name, prior, taсt, dur);
	return task;

}
Task* TaskGenerator::autoGenerateTask(int timer) {
	srand(time(NULL));
	int prior; // приоритет
	int taсt = timer; // время поступления 
	int dur; // время выполнения
	string name = "Задача # " + to_string(timer);
	prior = 1 + rand() % 3;
	dur = 1 + rand() % 5;
	cout << name << endl;
	cout << "Приоритет задачи " << prior << endl;
	cout << "Продолжительность задачи " << dur << endl;
	cout << "Время поступления задачи " << taсt << endl;
	Task* task = new Task(name, prior, taсt, dur);
	return task;

}