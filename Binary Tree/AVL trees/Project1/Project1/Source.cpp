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
			int h = max(count_height(x->left), count_height(x->right))+1;
			return h;
		}
		return 0;
	}
	int balance_factor(node *x) {
		return count_height(x->left) - count_height(x->right);
	}
	node * insert_node(node *x,int key) {
		if (x == nullptr) {
			x = new node;
			x->key = key;
			x->left = x->right = nullptr;
			return x;
		}
		if (key == x->key)
			return NULL;
		else if (key < x->key) {
			x->left = insert_node(x->left, key);
		}
		else {
			x->right = insert_node(x->right, key);
		}
		return x;

	}
	
	void LLrotation(node *x) {
		if (balance_factor(x) == 2 && balance_factor(x->left) == 1) {
			node *t;
			t = x->left;
			x->left = t->right;
			t->right = x;
			root = t;
			
		}
	}
	void print_inorder(node *x) {
		if (x) {
			print_inorder(x->left);
			cout << x->key << " ";
			print_inorder(x->right);
		}
	}
	void LLrotate(node *x) {
		if (x) {
			LLrotation(x);
			LLrotate(x->left);
			LLrotate(x->right);
		}
	}

	void RRrotation(node *x) {
		if (balance_factor(x) == 2 && balance_factor(x->right)) {
			node *t = x->right;
			x->right = t->left;
			t->left = x;
			root = t;
		}
	}
	void RRrotate(node *x) {
		if (x) {
			RRrotation(x);
			RRrotate(x->left);
			RRrotate(x->right);
		}
	}
	void print_bf(node *x) {
		if (x) {
			print_bf(x->left);
			cout << balance_factor(x) << " , ";
			print_bf(x->right);
		}
	}
};

int main() {

	Tree t;
	int key = 0;
	cin >> key;
	t.root = t.insert_node(t.root, key);
	while (key != -1) {
		cout << "cin: "; cin >> key;
		if (key == -1)break;
		t.insert_node(t.root,key);
		
	}
	t.LLrotate(t.root);
	//t.RRrotate(t.root);
	t.print_inorder(t.root); cout << endl;
	cout << "Visina stabla: "<< t.count_height(t.root) << endl;
	 t.print_bf(t.root);
	//cout << "Balance faktor(preorder): "; t.print_bf(t.root);
	cout << endl;
	system("pause");
	return 0;
}