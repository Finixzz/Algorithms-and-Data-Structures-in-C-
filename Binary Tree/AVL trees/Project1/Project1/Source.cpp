#include<iostream>

using namespace std;

struct node {
	node *left;
	int key;
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
	void insert_node(int key) {
		node *x = root;
		node *t = nullptr;
		if (!root) {
			root = new node;
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
		}
		node*p = new node;
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
	
	
	
};

int main() {

	Tree t;
	t.create_bst();
	
	system("pause");
	return 0;
}