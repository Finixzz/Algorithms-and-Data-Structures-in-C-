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
	void oslobodi_memoriju(node *x);

	int count_height(node *x);
	int balance_factor(node *x);
	node *LLrotation(node *x);
	node *RRrotation(node *x);
	node *LRrotation(node *x);
	node *RLrotation(node *x);
	node *Balance(node *x);

	node *insert_node(node *x, int key) {
		node *t;
		if (x == nullptr) {
			t = new node;
			t->key = key;
			t->left = t->right = nullptr;
			return t;
		}
		if (key < x->key) 
			x->left = insert_node(x->left, key);
		else if (key > x->key) 
			x->right = insert_node(x->right, key);
		return Balance(x);
	}

	void print_inorder(node *x);
	void print_balance_factor(node *x);
};
void Tree::oslobodi_memoriju(node *x) {
	if (x) {
		oslobodi_memoriju(x->left);
		oslobodi_memoriju(x->right);
		free(x);
	}
}
int Tree::count_height(node *x) {
	if (x) return max(count_height(x->left), count_height(x->right)) + 1;
	return 0;
}
int Tree::balance_factor(node *x) {
	if (x) return count_height(x->left) - count_height(x->right);
	return 0;
}
node *Tree::LLrotation(node *x) {
	node *l = x->left;
	x->left = l->right;
	l->right = x;

	if(root==x)root = l;
	return l;
}
node *Tree::RRrotation(node *x) {
	node *r = x->right;
	x->right = r->left;
	r->left = x;

	if(root==x)root = r;
	return r;
}
node *Tree::LRrotation(node *x) {
	node *l = x->left;
	node *lr = l->right;

	l->right = lr->left;
	x->left = lr->right;
	lr->left = l;
	lr->right = x;

	if(root==x)root = lr;
	return lr;
}
node *Tree::RLrotation(node *x) {
	node *r = x->right;
	node *rl = r->left;

	x->right = rl->left;
	r->left = rl->right;
	rl->left = x;
	rl->right = r;

	if(root==x)root = rl;
	return rl;
}
node *Tree::Balance(node *x) {
	if (balance_factor(x) == 2 && balance_factor(x->left) == 1) 
		return LLrotation(x);
	else if (balance_factor(x) == -2 && balance_factor(x->right) == -1) 
		return RRrotation(x);
	else if (balance_factor(x) == 2 && balance_factor(x->left) == -1) 
		return LRrotation(x);
	else if (balance_factor(x) == -2 && balance_factor(x->right) == 1) 
		return RLrotation(x);
	else return x;
}
void Tree::print_inorder(node *x) {
	if (x) {
		print_inorder(x->left);
		cout << x->key << " ";
		print_inorder(x->right);
	}
}
void Tree::print_balance_factor(node *x) {
	if (x) {
		print_balance_factor(x->left);
		cout << balance_factor(x) << " ";
		print_balance_factor(x->right);
	}
}

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
	cout << "Inorder balance faktori: "; t.print_balance_factor(t.root); cout << endl;

	system("pause");
	return 0;
}