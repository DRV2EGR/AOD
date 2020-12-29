#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Node {
public:
	int count;
	char symbol;
	Node* left;
	Node* right;

	Node() { }

	Node(char symbol, int count) {
		this->symbol = symbol;
		this->count = count;
	}

	Node(Node* l, Node* r) {
		symbol = 0;
		left = l;
		right = r;
		count = l->count + r->count;
	}

	static void print(Node* root, int depth = 0) {
		if (!root) return;

		if (root->symbol) {
			for (int i = 0; i < depth; i++) { cout << "."; }
			cout << root->symbol << endl;
		}
		else { depth++; }
		print(root->left, depth);
		print(root->right, depth);
	}
};

void buildTable(Node* root, vector<bool>& code, map<char, vector<bool>>& table) {
	if (root->left) {
		code.push_back(0);	// налево - 0/f
		buildTable(root->left, code, table);
	}

	if (root->right) {
		code.push_back(1);	// направо - 1/t
		buildTable(root->right, code, table);
	}

	if (root->symbol) { table[root->symbol] = code; }
	if (code.size()) { code.pop_back(); }
}

bool sortNode(const Node* a, const Node* b) {
	return a->count < b->count;
}

string decode(string& str, map<vector<bool>, char>& table) {
	string out = "";
	vector<bool> code;
	for (int i = 0; i < str.length(); i++) {
		code.push_back(str[i] == '0' ? false : true);
		if (table[code]) {
			out += table[code];
			code.clear();
		}
	}
	return out;
}

int main() {
	setlocale(LC_ALL, "RUS");
	string raw = "Рогов Дмитрий Вадимович";
	map<char, int> symbols;

	for (int i = 0; i < raw.length(); i++) { symbols[raw[i]]++; }

	list<Node*> trees;
	map<char, int>::iterator itr;
	for (itr = symbols.begin(); itr != symbols.end(); itr++) {
		Node* p = new Node(itr->first, itr->second);
		trees.push_back(p);
	}

	while (trees.size() != 1) {
		trees.sort(sortNode);

		Node* l = trees.front();
		trees.pop_front();
		Node* r = trees.front();
		trees.pop_front();

		Node* parent = new Node(l, r);
		trees.push_back(parent);
	}

	Node* root = trees.front();
	root->print(root);

	vector<bool> code;
	map<char, vector<bool> > table;
	buildTable(root, code, table);


	for (itr = symbols.begin(); itr != symbols.end(); itr++) {
		cout << itr->first << " - ";
		for (int j = 0; j < table[itr->first].size(); j++) {
			cout << table[itr->first][j];
		}
		cout << endl;
	}


	string out = "";
	for (int i = 0; i < raw.length(); i++) {
		for (int j = 0; j < table[raw[i]].size(); j++) {
			out += table[raw[i]][j] + '0';
		}
	}
	cout << endl << out.c_str() << endl;


	map<vector<bool>, char> ftable;
	for (auto i = table.begin(); i != table.end(); i++) { ftable[i->second] = i->first; }
	cout << endl << decode(out, ftable).c_str() << endl;

	while (true);
}

/*
	Максимальная сложность O(n).
*/