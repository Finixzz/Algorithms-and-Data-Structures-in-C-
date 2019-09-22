#include<iostream>

using namespace std;

struct node {
	node *left;
	int key;
	node *right;
};
class Queue {
public:
	Queue() :
		front{ -1 }, rear{ -1 }, size{ 20 }{
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
	node*dequeue() {
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
struct Stack {
public:
	Stack() :
		top{ -1 }, size{ 20 }, S{ nullptr }{
		S = new node*[size];
	}
	~Stack() {
		delete[]S; S = nullptr;
	}

	void push(node *x) {
		if (top == size - 1) {
			cout << "Stack overflow! " << endl;
		}
		else {
			top++;
			x = S[top];
		}
	}
	node *pop() {
		node *x = nullptr;
		if (top == -1) {
			cout << "Stack underflow! " << endl;
		}
		else {
			x = S[top--];
		}
		return x;
	}
	int isEmpty() {
		return top == -1;
	}
private:
	int top, size;
	node **S;
};
class Tree {
public:
	node *root;
	Queue q;
	Stack st;

	Tree() :
		root{ nullptr }, q{}, st{}{
		root = new node;
	}
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

	void create() {
		node *p, *t;
		int x;
		cout << "Unesite root vrijednost: ";
		cin >> root->key;
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

	void print_lorder(node *x) {
		cout << x->key << " ";
		q.enqueue(x);
		while (!q.isEmpty()) {
			x = q.dequeue();
			if (x->left) {
				cout << x->left->key << " ";
				q.enqueue(x->left);
			}
			if (x->right) {
				cout << x->right->key << " ";
				q.enqueue(x->right);
			}
		}
	}
	void input_node() {
		int key;
		cout << "Unesite vrijednost novog vrha: "; cin >> key;
		input(root, key);
	}
	void input(node *x, int key) {
		node *t = nullptr;
		while (x) {
			t = x;
			if (key == x->key)
				return;
			else if (key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		node *p = new node;
		p->key = key;
		p->left = p->right = nullptr;
		if (t->key > p->key)t->left = p;
		else t->right = p;
	}
	void RBserach() {
		int key;
		cout << "Unesite vrijednost za pretrazivanje: "; cin >> key;
		if (Rsearch(root, key) == true) {
			cout << "Trazeni clan postoji u stablu! " << endl;
		}
		else {
			cout << "Trazeni clan ne postoji! " << endl;
		}
	}
	bool Rsearch(node *x, int key) {
		if (!x)
			return false;
		if (key == x->key) {
			return true;
		}
		else if (key < x->key) {
			return Rsearch(x->left, key);
		}
		else
			return Rsearch(x->right, key);
	}

	void Bsearch() {
		int key;
		cout << "Unesite vrijednost za pretragu: "; cin >> key;
		if (search(root, key)) {
			cout << "Trazeni clan postoji u stablu! " << endl;
		}
		else {
			cout << "Trazeni clan ne postoji! " << endl;
		}
	}
	bool search(node *x, int key) {
		while (x) {
			if (key == x->key)
				return true;
			else if (key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		return false;
	}
};
int main() {

	Tree t;
	
	system("pause");
	return 0;
}