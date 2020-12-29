
/*
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




struct comp {
	int category;
	int nomer;
	int time;

	comp* next; //Ссылка на следущий элемент списка
};

struct dyn_list {
	comp* head; // Первый элемент (голова) списка
	comp* tail; // Последний элемент (хвост) списка
};

// Создание пустого списка
void constr_list(dyn_list& l)
{
	l.head = NULL;
}
// Проверка списка на пустоту
bool chk_empty(dyn_list l)
{
	return (l.head == NULL);
}

// Включение в список нового компонента
void comp_in(dyn_list& l, int a, int b, int d)
{
	comp* c = new comp();
	c->category = a;
	c->nomer = b;
	c->time = d;

	c->next = NULL;

	if (chk_empty(l))
		l.head = c;
	else
		l.tail->next = c;
	l.tail = c;
}

// Удаление компонента из списка
void comp_del(dyn_list& l, comp* c)
{
	if (c == l.head)
	{
		l.head = c->next;
		return;
	}
	comp* r = new comp();
	r = l.head;
	while (r->next != c)
		r = r->next;
	r->next = c->next;
	delete c;
}

//
comp* first_o(dyn_list l)
{
	comp* co = l.head;
	for (int i = 1; i < 4; ++i) {
		while (co->next != NULL) {
			if (co->category == i) {
				comp* tmp = co;
				comp_del(l, co);
				return tmp;
			}
			co = co->next;
		}

		if (co->category == i) {
			comp* tmp = co;
			comp_del(l, co);
			return tmp;
		}
	}
}



// Изменение значения компонента
void comp_edit(comp& c, char* v)
{

}


*/