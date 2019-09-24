#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
            PROBLEM
Input nodes of binary tree and check
weather or not is inputted binary tree
binary search tree or not
*/

struct node {
	node* left;
	int key;
	node* right;
};

class Queue {
private:
	int front, rear, size;
	node** Q;
public:
	Queue() :
		front{ -1 }, rear{ -1 }, size{ 100 }, Q{ nullptr }{
		Q = new node *[size];
	}
	~Queue() {
		delete[]Q; Q = nullptr;
	}

	void enqueue(node * x) {
		if (rear == size - 1) {
			cout << "Queue is full! " << endl;
		}
		else {
			rear++;
			Q[rear] = x;
		}
	}

	node * dequeue() {
		node* x = nullptr;
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
};
class Tree {
public:
	node* root;
	Queue q;
	vector<int> v;
	Tree() :
		root{ nullptr }, q{}{}
	~Tree() {
		oslobodi_memoriju(root);
	}
	void oslobodi_memoriju(node* x) {
		if (x) {
			oslobodi_memoriju(x->left);
			oslobodi_memoriju(x->right);
			free(x);
		}
	}

	void create() {
		node* t, *p;
		int x;
		root = new node;
		cout << "Unesite root vrijednost: "; cin >> root->key;
		root->left = root->right = nullptr;
		q.enqueue(root);
		while (!q.isEmpty()) {
			p = q.dequeue();
			cout << "Unesite vrijednost lijevog dijeteta od " << p->key << ": ";
			cin >> x;
			if (x != -1) {
				t = new node;
				t->key = x;
				t->left = t->right = nullptr;
				p->left = t;
				q.enqueue(t);
			}
			cout << "Unesite vrijednost desnog dijeteta od " << p->key << ": ";
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

	void push_vector(node* x) {
		if (x) {
			push_vector(x->left);
			v.push_back(x->key);
			push_vector(x->right);
		}
	}
	void is_bst() {
		push_vector(root);
		if (is_sorted(begin(v), end(v))) {
			cout << "Jeste" << endl;
		}
		else {
			cout << "Nije" << endl;
		}
	}
};

int main() {

	Tree t;
	t.create();
	t.is_bst();

	system("pause");
	return 0;
}