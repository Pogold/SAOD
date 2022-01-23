#pragma once
#pragma once
#include"Task.h"
#include<iostream>
#include<string>
using namespace std;

class TaskGenerator {
public:
	Task* generateTask(int time);
	Task* autoGenerateTask(int time);
};