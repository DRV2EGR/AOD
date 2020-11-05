#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 6
int main() {
	setlocale(LC_ALL, "RUS");
	int a[SIZE][SIZE]; // матрица связей
	int d[SIZE]; // минимальное расстояние
	int v[SIZE]; // посещенные вершины
	int temp, minindex, min;
	system("chcp 1251");
	system("cls");
	// Инициализация матрицы связей
	for (int i = 0; i < SIZE; i++)
	{
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++) {
			printf("Введите расстояние %d - %d: ", i + 1, j + 1);
			scanf("%d", &temp);
			a[i][j] = temp;
			a[j][i] = temp;
		}
	}
	// Вывод матрицы связей
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
	//Инициализация вершин и расстояний
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	d[0] = 0;
	// Шаг алгоритма
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((v[i] == 1) && (d[i] < min))
			{ // Переприсваиваем значения
				min = d[i];
				minindex = i;
			}
		}
		// Добавляем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	// Вывод кратчайших расстояний до вершин
	printf("\nКратчайшие расстояния до вершин: \n");
	for (int i = 0; i < SIZE; i++)
		printf("%5d ", d[i]);

	// Восстановление пути
	int ver[SIZE]; // массив посещенных вершин
	int end = 4; // индекс конечной вершины = 5 - 1
	ver[0] = end + 1; // начальный элемент - конечная вершина
	int k = 1; // индекс предыдущей вершины
	int weight = d[end]; // вес конечной вершины

	while (end != 0) // пока не дошли до начальной вершины
	{
		for (int i = 0; i < SIZE; i++) // просматриваем все вершины
			if (a[i][end] != 0)   // если связь есть
			{
				int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
				if (temp == d[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохраняем новый вес
					end = i;       // сохраняем предыдущую вершину
					ver[k] = i + 1; // и записываем ее в массив
					k++;
				}
			}
	}
	// Вывод пути (начальная вершина оказалась в конце массива из k элементов)
	printf("\nВывод кратчайшего пути\n");
	for (int i = k - 1; i >= 0; i--)
		printf("%5d ", ver[i]);
	//Представление графа в виде дерева
	printf("\nПредставление графа в виде дерева\n");
	bool first = true;
	printf("\n|1|\n");
	int now[SIZE * SIZE] = { 1,0,0,0,0 };
	int next[SIZE * SIZE] = { 0,0,0,0,0 };
	int index = 0;
	for (int k = 0; k < SIZE - 1; k++) { //уровни дерева
		std::cout << "|";
		for (int i = 0; i < SIZE - 1; i++) { //переход по родителям
			if (now[i] != 0 && now[i] != 6) {
				for (int j = now[i]; j <= SIZE; j++) { //ветки от одного родителя
					if (a[j - 1][now[i] - 1] != 0) {
						if (first) { first = false; std::cout << j; }
						else { std::cout << " " << j; }
						next[index] = j;
						index++;
					}
				}
				std::cout << "|";
				first = true;
			}
			else if (now[i] == 6) {
				std::cout << " |";
			}
		}
		std::cout << std::endl;
		index = 0;
		for (int q = 0; q < SIZE - 1; q++) { now[q] = next[q]; next[q] = 0; }
	}
	return 0;
}

/*
2
4
5
0
0
0
4
3
0
0
0
7
6
4
2
*/