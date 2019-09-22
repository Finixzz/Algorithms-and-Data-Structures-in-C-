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
		front{ -1 }, rear{ -1 }, size{ 100 }, Q{ nullptr }{
		Q = new node*[100];
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
class Stack {
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
			S[top] = x;
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

	int isEmpty() { return top == -1; }
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
		root{ nullptr }, q{}, st{}{}
	~Tree() {
		oslobodi_memoriju(root);
	}
	void oslobodi_memoriju(node *x);

	void create();

	void print_preorder(node *x);
	void print_inorder(node *x);
	void print_postorder(node *x);

	void iterative_preorder(node *x);
	void iterative_inorder(node *x);
	void iterative_level_order(node *x);

	int count_nodes(node *x);
	int count_height(node *x);
	int count_internal(node *x);
	int count_external(node *x);
	int count_deg2(node *x);
	int count_deg1(node *x);
};
void Tree::oslobodi_memoriju(node *x) {
	if (x != nullptr) {
		oslobodi_memoriju(x->left);
		oslobodi_memoriju(x->right);
		free(x);
	}
}
void Tree::create() {
	node *p, *t;
	int x;
	root = new node;
	cout << "Unesite root vrijednost: "; cin >> root->key;
	root->left = root->right = nullptr;
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout << "Unesite vrijednost lijevog djeteta od " << p->key << ": ";
		cin >> x;
		if (x != -1) {
			t = new node;
			t->key = x;
			t->left = t->right = nullptr;
			p->left = t;
			q.enqueue(t);
		}
		cout << "Unesite vrijednost desnog djeteta od " << p->key << ": ";
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
void Tree::print_preorder(node *x) {
	if (x) {
		cout << x->key << " ";
		print_preorder(x->left);
		print_preorder(x->right);
	}
}
void Tree::print_inorder(node *x) {
	if (x) {
		print_preorder(x->left);
		cout << x->key << " ";
		print_preorder(x->right);
	}
}
void Tree::print_postorder(node *x) {
	if (x) {
		print_postorder(x->left);
		print_postorder(x->right);
		cout << x->key << " ";
	}
}

void Tree::iterative_preorder(node *x) {
	while (x || !st.isEmpty()) {
		if (x) {
			cout << x->key << " ";
			st.push(x);
			x = x->left;
		}
		else {
			x = st.pop();
			x = x->right;
		}
	}
}

void Tree::iterative_inorder(node *x) {
	while (x || !st.isEmpty()) {
		if (x) {
			st.push(x);
			x = x->left;
		}
		else {
			x = st.pop();
			cout << x->key << " ";
			x = x->right;
		}
	}
}
void Tree::iterative_level_order(node *x) {
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
int Tree::count_nodes(node *x) {
	static int br = 0;
	if (x) {
		count_nodes(x->left);
		count_nodes(x->right);
		br++;
		return br;
	}
	return 0;
}
int Tree::count_height(node *x) {
	static int br1 = 0; static int br2 = 0;
	if (x) {
		count_height(x->left);
		count_height(x->right);
		if (x->left) br1++;
		if (x->right) br2++;
		if (br1 > br2)
			return br1;
		return br2;
	}
	return 0;
}
int Tree::count_internal(node *x) {
	static int br = 0;
	if (x) {
		count_internal(x->left);
		count_internal(x->right);
		if (x->left || x->right) {
			br++;
		}
		return br;
	}
	return 0;
}
int Tree::count_external(node *x) {
	static int br = 0;
	if (x) {
		count_external(x->left);
		count_external(x->right);
		if (!x->left && !x->right) br++;
		return br;
	}
	return 0;
}
int Tree::count_deg2(node *x) {
	static int br = 0;
	if (x) {
		count_deg2(x->left);
		count_deg2(x->right);
		if (x->left&&x->right) br++;
		return br;
	}
	return 0;
}
int Tree::count_deg1(node *x) {
	static int br = 0;
	if (x) {
		count_deg1(x->left);
		count_deg1(x->right);
		if ((!x->left&&x->right) || (x->left && !x->right))br++;
		return br;
	}
	return 0;
}
int main() {

	Tree t;
	t.create();
	cout << "--------------------------------------\n";
	cout << "   Osobine unesenog binarnog stabla\n";
	cout << "--------------------------------------\n";
	cout << "Preorder: "; t.print_preorder(t.root); cout << endl;
	cout << "Inorder: "; t.print_inorder(t.root); cout << endl;
	cout << "Postorder: "; t.print_postorder(t.root); cout << endl;
	cout << "--------------------------------------\n";
	cout << "Ipreorder: "; t.iterative_preorder(t.root); cout << endl;
	cout << "Iinorder: "; t.iterative_inorder(t.root); cout << endl;
	cout << "ILevelorder:"; t.iterative_level_order(t.root); cout << endl;
	cout << "--------------------------------------\n";
	cout << "Broj vrhova: " << t.count_nodes(t.root) << endl;
	cout << "Visina: " << t.count_height(t.root) << endl;
	cout << "Broj unutrasnjih vrhova: " << t.count_internal(t.root) << endl;
	cout << "Broj vanjskih vrhova: " << t.count_external(t.root) << endl;
	cout << "Broj vrhova sa stepenom 1, deg(1): " << t.count_deg1(t.root) << endl;
	cout << "Broj vrhova sa stepenom 2, deg(2): " << t.count_deg2(t.root) << endl;
	cout << "--------------------------------------\n";

	system("pause");
	return 0;
}