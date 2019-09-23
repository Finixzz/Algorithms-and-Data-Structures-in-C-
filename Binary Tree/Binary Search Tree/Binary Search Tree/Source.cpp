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

	Tree():
		root{nullptr}{}
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
	void insert(int key) {
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
		int n, key;
		cout << "Unesite broj vrhova stabla: "; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Unesite vrijednost vrha: "; cin >> key;
			insert(key);
		}
	}
	void print_inorder(node *x) {
		if (x) {
			cout << x->key << " ";
			print_inorder(x->left);
			print_inorder(x->right);
		}
	}
};

int main() {

	Tree t;
	t.create_bst();
	t.print_inorder(t.root);
	//Nastavi dalje
	system("pause");
	return 0;
}