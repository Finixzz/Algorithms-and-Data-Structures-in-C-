#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	node *left;
	int key;
	int height;
	node *right;
};
class Tree {
public:
	node *root;

	Tree() :
		root{ nullptr } {}
	~Tree() {
		oslobodi_memoriju(root);
	}
	void oslobodi_memoriju(node *x) {
		if (x) {
			oslobodi_memoriju(x->left);
			oslobodi_memoriju(x->right);
			free(x);
		}
	}
	int count_height(node *x) {
		if (x) {
			int h = max(count_height(x->left), count_height(x->right))+1;
			return h;
		}
		return 0;
	}
	int balance_factor(node *x) {
		return count_height(x->left) - count_height(x->right);
	}
	void insert_node(int key) {
		node *x = root;
		node *t = nullptr;
		node *p = new node;
		p->height = 1;
		if (!root) {
			root = new node;
			root->height = 1;
			root->key = key;
			root->left = root->right = nullptr;
			return;
		}
		while (x) {
			t = x;
			if (key == x->key)
				return;
			else if (key < x->key)
				x = x->left;
			else
				x = x->right;
			p->height++;
		}
		p->key = key;
		p->left = p->right = nullptr;
		if (t->key > p->key)t->left = p;
		else t->right = p;
	}
	void create_bst() {
		int  key = 0;
		cout << "Za prekid unesite -1!\n";
		while (key != -1) {
			cout << "Unesite vrijednost vrha: "; cin >> key;
			if (key == -1)break;
			insert_node(key);
		}
	}
	void print_bf(node *x) {
		if (x) {
			print_bf(x->left);
			cout << balance_factor(x) << " ";
			print_bf(x->right);
		}
	}
};

int main() {

	Tree t;
	t.create_bst();
	cout << "Visina stabla: "<< t.count_height(t.root) << endl;
	cout << "Balance faktor(preorder): "; t.print_bf(t.root);
	cout << endl;
	system("pause");
	return 0;
}