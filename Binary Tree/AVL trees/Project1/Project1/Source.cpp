#include<iostream>
#include<algorithm>

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

	int count_height(node *x) {
		if (x) {
			return max(count_height(x->left), count_height(x->right)) + 1;
		}
		return 0;
	}
	int balance_factor(node *x) {
		if (x) {
			return count_height(x->left) - count_height(x->right);
		}
		return 0;
	}

	node *LLrotation(node *x) {
		node *t = x->left;
		x->left = t->right;
		t->right = x;
		root = t;
		return t;
	}
	node *LRrotation(node *x) {
		node *l = x->left;
		node *lr = x->left->right;

		l->right = lr->left;
		x->left = lr->right;
		lr->left = l;
		lr->right = x;
		root = lr;
		return lr;
	}
	node *RRrotation(node *x) {
		node *t = x->right;
		x->right = t->left;
		t->left = x;
		root = t;
		return t;
	}
	node *insert_node(node *x, int key) {
		if (x == nullptr) {
			x = new node;
			x->key = key;
			x->left = x->right = nullptr;
			return x;
		}
		if (key == x->key)
			return 0;
		else if (key < x->key)
			x->left = insert_node(x->left, key);
		else
			x->right = insert_node(x->right, key);

		if (balance_factor(x) == 2 && balance_factor(x->left) == 1) {
			return LLrotation(x);
		}
		if (balance_factor(x) == -2 && balance_factor(x->right) == -1) {
			return RRrotation(x);
		}
		if (balance_factor(x) == 2 && balance_factor(x->left) == -1) {
			return LRrotation(x);
		}
		return x;
	}

	void print_inorder(node *x) {
		if (x) {
			print_inorder(x->left);
			cout << x->key << " ";
			print_inorder(x->right);
		}
	}
};


int main() {


	Tree t;
	int key = 0;
	cout << "Unesite root vrijednost: "; cin >> key;
	t.root = t.insert_node(t.root, key);
	while (key != -1) {
		cout << "Unesite vrijednost vrha: "; cin >> key;
		if (key == -1)break;
		t.insert_node(t.root, key);
	}
	cout << "Inorder: "; t.print_inorder(t.root); cout << endl;
	system("pause");
	return 0;
}