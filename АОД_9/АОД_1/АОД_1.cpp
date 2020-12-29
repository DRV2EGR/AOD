#include <iostream>
#include <vector>
#include <string>
using namespace std;

//#include "Source.cpp"
struct employe {
	int category;
	int id;
	int time;
};


class Queue_Dinamich_Mass {
	employe* queue;
	int frnt, rear;
	int nom;
public:
	Queue_Dinamich_Mass(int r);
	void push(employe _num);
	void out();
	int size();
	void pop();
	employe front();
	employe back();
	bool if_full();
	bool if_pust();
};
//Конструктор
Queue_Dinamich_Mass::Queue_Dinamich_Mass(int r) {
	this->queue = new employe[r];
	frnt = rear = 0;
	nom = r;
}
//Вывод элементов очереди
void Queue_Dinamich_Mass::out() {
	for (int i = frnt + 1; i < rear + 1; i++) {
		cout << " " << queue[i].time;
	}
}
//Помещение элемента в очередь
void Queue_Dinamich_Mass::push(employe _num) {
	if (rear + 1 == frnt || (rear + 1 == nom && !frnt)) {
		cout << "очередь полна" << endl;
		return;
	}
	rear++;
	if (rear == nom) rear = 0;
	queue[rear] = _num;
}

//Определение размера очереди
int Queue_Dinamich_Mass::size() {
	int s = 0;
	for (int i = frnt; i < rear; i++)
		s++;
	return s;
}
// Последний элемент очереди
employe Queue_Dinamich_Mass::back() {
	return queue[rear];
}
// Первый элемент очереди
employe Queue_Dinamich_Mass::front() {
	for (int i = 1; i < 4; ++i) {
		bool f = false;
		for (int j = frnt; j < nom; ++j) {
			if (queue[j].category == i) {
				employe ee = queue[j];
				for (int k = j + 1; k < nom; ++k) {
					queue[k - 1] = queue[k];
				}
				rear--;
				return ee;
			}
		}
	}
	//return queue[frnt + 1];
}

bool Queue_Dinamich_Mass::if_full()
{
	if (rear + 1 == frnt || (rear + 1 == nom && !frnt)) {
		return true;
	}
	return false;
}

bool Queue_Dinamich_Mass::if_pust()
{
	if (frnt == rear) {
		return true;
	}
	return false;
}



int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Введите заявки (для выхода введите 0, не более 100 заявок) " << endl;

	Queue_Dinamich_Mass* queue = new Queue_Dinamich_Mass(100);

	int cat;
	int no;
	int ti;
	do {
		cin >> cat >> no >> ti;

		if (cat != 0) {
			employe em;
			em.category = cat;
			em.id = no;
			em.time = ti;

			queue->push(em);
		}

	} while (cat != 0);

	int time_1 = 0;
	int time_2 = 0;
	int time_3 = 0;

	string* info = new string[100];
	int i = 0;

	//queue->out();

	while (!queue->if_pust()) {
		employe r = queue->front();

		if (r.category == 1) {
			time_1 += r.time;
			info[i] = to_string(r.category) + " " +
				to_string(r.id) + " " + to_string(r.time);
		}
		else if (r.category == 2) {
			time_2 += r.time;
			info[i] = to_string(r.category) + " " +
				to_string(r.id) + " " + to_string(r.time);
		}
		else if (r.category == 3) {
			time_3 += r.time;
			info[i] = to_string(r.category) + " " +
				to_string(r.id) + " " + to_string(r.time);
		}

		i++;
	}

	cout << "\n\n\n";
	cout << "Time 1: " << time_1 << endl;
	cout << "Time 2: " << time_2 << endl;
	cout << "Time 3: " << time_3 << endl;

	cout << "\n\n\nZayavki\n";
	for (int j = 0; j < i; ++j) {
		cout << info[j] << endl;
	}
	
	return 0;
}
/*
void massiv()
{
	cout << "Введите заявки (для выхода введите 0, не более 100 заявок) " << endl;

	Queue_Dinamich_Mass* queue = new Queue_Dinamich_Mass(100);

	int cat;
	int no;
	int ti;
	do {
		cin >> cat >> no >> ti;

		if (cat != 0) {
			employe em;
			em.category = cat;
			em.id = no;
			em.time = ti;

			queue->push(em);
		}

	} while (cat != 0);

	int time_1 = 0;
	int time_2 = 0;
	int time_3 = 0;

	string* info = new string[100];
	int i = 0;

	//queue->out();

	while (!queue->if_pust()) {
		employe r = queue->front();

		if (r.category == 1) {
			time_1 += r.time;
			info[i] = to_string(r.category) + " " +
				to_string(r.id) + " " + to_string(r.time);
		}
		else if (r.category == 2) {
			time_2 += r.time;
			info[i] = to_string(r.category) + " " +
				to_string(r.id) + " " + to_string(r.time);
		}
		else if (r.category == 3) {
			time_3 += r.time;
			info[i] = to_string(r.category) + " " +
				to_string(r.id) + " " + to_string(r.time);
		}

		i++;
	}

	cout << "\n\n\n";
	cout << "Time 1: " << time_1 << endl;
	cout << "Time 2: " << time_2 << endl;
	cout << "Time 3: " << time_3 << endl;

	cout << "\n\n\nZayavki\n";
	for (int j = 0; j < i; ++j) {
		cout << info[j] << endl;
	}

}

void foo() 
{
cout << "Введите заявки (для выхода введите 0, не более 100 заявок) " << endl;

	dyn_list* queue = new dyn_list();

	int cat;
	int no;
	int ti;
	do {
		cin >> cat >> no >> ti;

		if (cat != 0) {
			comp_in(*queue, cat, no, ti);
		}

	} while (cat != 0);

	int time_1 = 0;
	int time_2 = 0;
	int time_3 = 0;

	string* info = new string[100];
	int i = 0;

	while (!chk_empty(*queue)) {
		comp* r = first_o(*queue);

		if (r->category == 1) {
			time_1 += r->time;
			info[i] = to_string(r->category) + " " +
				to_string(r->category) + " " + to_string(r->time);
		}
		else if (r->category == 2) {
			time_2 += r->time;
			info[i] = to_string(r->category) + " " +
				to_string(r->category) + " " + to_string(r->time);
		}
		else if (r->category == 3) {
			time_3 += r->time;
			info[i] = to_string(r->category) + " " +
				to_string(r->category) + " " + to_string(r->time);
		}

		i++;
	}

	cout << "\n\n\n";
	cout << "Time 1: " << time_1 << endl;
	cout << "Time 2: " << time_2 << endl;
	cout << "Time 3: " << time_3 << endl;

	cout << "\n\n\nZayavki\n";
	for (int j = 0; j < i; ++j) {
		cout << info[j] << endl;
	}
	}

*/