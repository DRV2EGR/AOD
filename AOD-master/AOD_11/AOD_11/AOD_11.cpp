#include <iostream>
#include <vector>
using namespace std;
// 6 Variant

class Book {
public:
	int ISBN;
	string author;
	string name;

	bool is_enabed;
};


Book* collision_list[13];


int h1(int k)
{
	return k % 13;
}

int h2(int k)
{
	return 1 + k % 11;
}

int solv_coll(int k, int i)
{
	cout << "collision at " << k << endl;
	return ((h1(k) + i * h2(k)) % 13);
}

int h(int k)
{
	int pred_res = k % 13;
	int i = 1;

	while (collision_list[pred_res]->is_enabed != false) {
		pred_res = solv_coll(k, i);
		i += 1;
	}

	return pred_res;
}

int main()
{
	for (int i = 0; i < 13; ++i) {
		collision_list[i] = new Book();
		collision_list[i]->is_enabed = false;
	}

	/*
	int sy; sy = 1;
	while (sy != 0) {
		cout << "ADD BOOK(1/0) ";
		cin >> sy;
		Book* book = new Book();
		cout << "ISBN: "; cin >> book->ISBN;
		//cout << "Author: "; cin >> book->author;
		//cout << "Name: "; cin >> book->name;
		book->is_enabed = true;

		int place = h(book->ISBN);
		collision_list[place] = book;
	}
	*/

	Book* book1 = new Book();
	book1->ISBN = 79;
	book1->author = "Pushkin";
	book1->name = "n/a";
	book1->is_enabed = true;

	int place = h(book1->ISBN);
	collision_list[place] = book1;

	Book* book2 = new Book();
	book2->ISBN = 69;
	book2->author = "Chechov";
	book2->name = "n/a";
	book2->is_enabed = true;

	place = h(book2->ISBN);
	collision_list[place] = book2;

	Book* book3 = new Book();
	book3->ISBN = 72;
	book3->author = "Tolstoy";
	book3->name = "n/a";
	book3->is_enabed = true;

	place = h(book3->ISBN);
	collision_list[place] = book3;

	Book* book4 = new Book();
	book4->ISBN = 98;
	book4->author = "Nekrasov";
	book4->name = "n/a";
	book4->is_enabed = true;

	place = h(book4->ISBN);
	collision_list[place] = book4;


	Book* book5 = new Book();
	book5->ISBN = 14;
	book5->author = "Lyenin";
	book5->name = "n/a";
	book5->is_enabed = true;

	place = h(book5->ISBN);
	collision_list[place] = book5;

	for (int i = 0; i < 13; ++i) {
		cout << collision_list[i]->ISBN << " ";
	}

	return 0;
}
