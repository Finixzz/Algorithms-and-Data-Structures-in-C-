#include<iostream>

using namespace std;
/*
                         Problem description
A unival tree (which stands for "universal value") is a tree where all nodes
under it have the same value. Given the root to a binary tree,
count the number of unival subtrees.
 */

struct node {
	node *left;
	int key;
	node *right;
};
class Queue {
public:
	Queue():
		front{ -1 }, rear{ -1 }, size{ 100 }, Q{ nullptr }{
		Q = new node*[size];
	}
	~Queue() {
		delete[]Q; Q = nullptr;
	}

	void enqueue(node *x) {
		if (rear == size - 1) {
			cout << "Queue is full! " << endl;
		}
		else {
			rear++;
			Q[rear] = x;
		}
	}
	node *dequeue() {
		node *x = nullptr;
		if (front == size - 1) {
			cout << "Queue is empty! " << endl;
		}
		else {
			front++;
			x = Q[front];
		}
		return x;
	}
	int isEmpty() {
		return front == rear;
	}
private:
	int front, rear, size;
	node **Q;
};
class Tree {
public:
	node *root;
	Queue q;
	
	Tree():
		root{ nullptr }, q{}{}
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

	void create();
};
void Tree::create() {
	node *t, *p;
	int x;
	root = new node;
	cout << "Unesite root vrijednost: "; cin >> root->key;
	root->left = root->right = nullptr;
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout << "Unesite lijevo dijete od " << p->key << ": ";
		cin >> x;
		if (x != -1) {
			t = new node;
			t->key = x;
			t->left = t->right = nullptr;
			p->left = t;
			q.enqueue(t);
		}
		cout << "Unesite desno dijete od " << p->key << ": ";
		cin >> x;
		if (x != -1) {
			t = new node;
			t->key = x;
			t->left = t->right = nullptr;
			p->right = t;
			q.enqueue(t);
		}
	}
}
int main() {

	Tree t;
	t.create();

	system("pause");
	return 0;
}