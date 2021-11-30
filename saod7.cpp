// saod7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include "stdafx.h"
#include <iostream>
using namespace std;
//
//const int Vmax = 100,
//Emax = Vmax * (Vmax - 1) / 2; //в случае, если граф полный
//
//int terminal[Emax], //массив вершин, в которые входят ребра
//    weight[Emax], // массив весов ребер
//    point[Emax]; //массив весов ребер
//
//int head[Vmax], //хранит для i-ой вершины номер k-ого элемента массивов terminal и weight, где terminal[k] – первая вершина смежная с i-ой, а weight[k] – вес инцидентного ей ребра
//    last[Vmax]; //хранит для i-ой вершины номер k-ого элемента массивов terminal и weight, где terminal[k] – последняя вершина смежная с i-ой, а weight[k] – вес инцидентного ей ребра
//
//int n, m, v, u, w, k = 0, i;
//char r;

//void Add(int v, int u, int w) //добавление ребра
//{
//	k = k + 1;
//	terminal[k] = u; 
//	weight[k] = w;
//	//если вершина v новая, то
//	//первая смежная ей вершина имеет номер k
//	if (head[v] == 0) head[v] = k;
//	//если вершина v уже просматривалась, то
//	//следующая смежная с ней вершина имеет номер k
//	if (last[v] != 0) point[last[v]] = k;
//	last[v] = k;
//}


//void output(int* v, ) //добавление ребра
//{
//	k = k + 1;
//	terminal[k] = u; 
//	weight[k] = w;
//	//если вершина v новая, то
//	//первая смежная ей вершина имеет номер k
//	if (head[v] == 0) head[v] = k;
//	//если вершина v уже просматривалась, то
//	//следующая смежная с ней вершина имеет номер k
//	if (last[v] != 0) point[last[v]] = k;
//	last[v] = k;
//}

//class Graph
//{
//public:
//	Dot arr;
//
//	class Dot
//	{
//	public:
//		int i;
//		int j;
//
//	}
//
//
//}
//главная функция
int main()
{
	setlocale(LC_ALL, "Rus");

	int edges[5][2] =
	{
	  { 1,2},
	  { 2,3},
	  { 3,4},
	  { 4,5},
	  { 5,1} };

	int graph[4][4] =
	{
	{ 0, 0, 0, 0}, // 1 2 3 4
	{ 0, 1, 1, 1}, // 5 6 7 8
	{ 0, 1, 0, 1}, // 9 10 11 12
	{ 0, 1, 1, 1} }; // 13 14 15 16


	int leftup[2];
	int rightup[2];
	int leftdown[2];
	int rightdown[2];
	int counter=0;
	int k;
	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (graph[i][j] == 1 && graph[i][j+1] == 1 && graph[i+1][j] == 1) //leftup
			{
				leftup[0] = i;
				leftup[1] = j;
				counter = j;

				do
				{
					counter++;
					rightup[0] = i;
					rightup[1] = j;
				} while (!(graph[i][k] == 1 && graph[i][k - 1] == 1 && graph[i + 1][k] == 1));
	
				if (counter!= rightup[1])
				{
					cout << "\n";
					break;
				}

			} else 	if (graph[i][j] == 1 && graph[i][j - 1] == 1 && graph[i + 1][j] == 1)//rightup
			{
				rightup[0] = i;
				rightup[1] = j;
			}
			else
			if (graph[i][j] == 1 && graph[i][j +1] == 1 && graph[i -1][j] == 1)//leftdown
			{
				leftdown[0] = i;
				leftdown[1] = j;
			}
			else
			if (graph[i][j] == 1 && graph[i][j - 1] == 1 && graph[i -1][j] == 1)//rightdown
			{
				rightdown[0] = i;
				rightdown[1] = j;
			}
		}
	}
	

	cout << "Список ребер(1-вершина из которой выходит ребро,2-куда приходит):\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			cout << edges[i][j] << " ";
		}
		cout << endl;
	}


	cout << "Прямоугольное изображение:\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
				cout << graph[i][j] << " ";
		}
		cout << endl;
	}


	cout << "leftup\n";
	cout << leftup[0] << " " << leftup[1] << endl;


	//cout << "Количество вершин:\n";
	//cin >> n;

	//cout << "Количество ребер:\n";
	//cin >> m;
	//int points[2][10], //массив вершин, в которые входят ребра
	//int* sides = new int[m], // массив весов ребер

	//cout << "Вводите ребра и их вес (v, u, w):\n";

	//for (i = 0; i < m; i++)
	//{
	//	cin >> v >> u >> w;
	//	cout << i <<": Ребро ориентированно? (y/n) >> ";
	//	cin >> r;
	//	if (r == 'y') 
	//		Add(v, u, w);
	//	else
	//	{
	//		Add(v, u, w);
	//		Add(u, v, w);
	//	}
	//	cout << endl;
	//}
	//m = m * 2;

	////вывод списка ребер
	//cout << "Список ребер графа:\n";
	//for (i = 0; i < m; i++)
	//{
	//	k = head[i];
	//	while (k > 0)
	//	{
	//		cout << "(" << i << "->" << terminal[k] << ")$=" << weight[k] << endl;
	//		k = point[k];
	//	}
	//}

	//for (i = 0; i < m; i++)
	//{
	//	k = head[i];
	//	while (k > 0)
	//	{
	//		cout << "(" << i << "->" << terminal[k] << ")$=" << weight[k] << endl;
	//		k = point[k];
	//	}
	//}

	return 0;
}