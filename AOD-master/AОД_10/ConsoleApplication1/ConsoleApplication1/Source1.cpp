#include <iostream>
using namespace std;

struct node // структура дл€ представлени€ узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int balancefactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (balancefactor(p) == 2)
	{
		if (balancefactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (balancefactor(p) == -2)
	{
		if (balancefactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);

	return balance(p);
}

node* find_min(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? find_min(p->left) : p;
}

node* remove_min(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}

node* remove(node* p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = find_min(r);
		min->right = remove_min(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void print_tree(node* t, int n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << " ";
	}
	std::cout << t->key << std::endl;

	if (t->right != NULL) {
		print_tree(t->right, n + 5);
	}
	if (t->left != NULL) {
		print_tree(t->left, n + 5);
	}
}

int main()
{
	// ѕростое AVL
	cout << "Input kol-vo";
	int n; cin >> n;

	cout << "Inp root ";
	int t;	cin >> t;
	node* root = insert(NULL, t);

	cout << "Inp mass: ";
	for (int i = 0; i < n; ++i) {
		cin >> t;

		root = insert(root, t);
	}

	print_tree(root, 0);


	return 0;
}