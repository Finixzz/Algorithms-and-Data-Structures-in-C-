#include<iostream>

using namespace std;

struct node {
	int key;
	node *next;
};

class Stack {
private:
	node *top;
public:
	Stack() :
		top{ nullptr } {};
	~Stack() {
		node *temp;
		while (top) {
			temp = top->next;
			free(top);
			top = temp;
		}
	}
	void push(int &);
	void pop();
	int isEmpty();
	bool isFull();
	void printStack();
	void peek();
};
void Stack::push(int &key) {
	node *temp = new node;
	if (temp) {
		temp->key = key;
		temp->next = nullptr;
		if (top == nullptr) {
			top = temp;
		}
		else {
			temp->next = top;
			top = temp;
		}
		cout << "Clan " << top->key << " unesen u stack! " << endl;
	}
	else
		cout << "Stack overflow! " << endl;
}
void Stack::pop() {
	if (top) {
		node *temp = top;
		top = top->next;
		cout << "Clan " << temp->key << " obrisan iz stacka! " << endl;
		free(temp);
	}
	else
		cout << "Stack underflow! " << endl;
}
int Stack::isEmpty() {
	return top == nullptr;
}
bool Stack::isFull() {
	node *temp = new node;
	if (temp) {
		delete temp;
		temp = nullptr;
		return false;
	}
	else
		return true;
}
void Stack::printStack() {
	if (top) {
		node *temp = top;
		cout << "Clanovi stacka su: ";
		while (temp) {
			cout << temp->key << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	else
		cout << "Stack je prazan! " << endl;
}
void Stack::peek() {
	if (top) {
		cout << "Zadnji uneseni clan u stack je: ";
		cout << top->key << endl;
	}
	else
		cout << "Stack je prazan! " << endl;
}
int menu() {
	int izbor;
	do {
		cout << "---------------\n";
		cout << "      MENU    \n";
		cout << "---------------\n";
		cout << "1) Push\n";
		cout << "2) Pop\n";
		cout << "3) Print Stack\n";
		cout << "4) Peek\n";
		cout << "5) END\n";
		cout << "---------------\n";
		cout << "Unesite izbor: "; cin >> izbor;
		return izbor;
	} while (1);
}

int main() {

	Stack *stack = new Stack;
	int izbor;
	do {
		izbor = menu();
		if (izbor < 0 || izbor>4) {
			delete stack; stack = nullptr;
			break;
		}
		if (izbor == 1) {
			int key;
			cout << "Unesite vrijednost u stack: ";
			cin >> key;
			stack->push(key);
			system("pause"); system("cls");
		}
		if (izbor == 2) {
			stack->pop();
			system("pause"); system("cls");
		}
		if (izbor == 3) {
			stack->printStack();
			system("pause"); system("cls");
		}
		if (izbor == 4) {
			stack->peek();
			system("pause"); system("cls");
		}
	} while (1);

	system("pause");
	return 0;
}