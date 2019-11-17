#include<iostream>

using namespace std;

class Stack {
private:
	int top, size;
	int *St;
public:
	Stack():
		top{-1},size{0},St{nullptr}{}
	~Stack() {
		delete[]St; St = nullptr;
	}

	void create();
	void push(int &);
	void pop();
	int isEmpty();
	int isFull();
	void printStack();
	void peek();
};
void Stack::create() {
	cout << "Unesite velicinu steka: "; cin >> this->size;
	St = new int[this->size];
}
void Stack::push(int &key) {
	if (this->top == this->size - 1)
		cout << "Stack overflow! " << endl;
	else {
		this->top++;
		St[top] = key;
		cout << "Clan " << St[top] << " unesen u stek! " << endl;
	}
}
void Stack::pop() {
	if (this->top == -1)
		cout << "Stack underflow!" << endl;
	else {
		cout << "Clan " << St[top] << " obrisan iz steka! " << endl;
		this->top--;
	}
}
int Stack::isEmpty() {
	return this->top == -1;
}
int Stack::isFull() {
	return this->top == this->size - 1;
}
void Stack::printStack() {
	if (!isEmpty()) {
		cout << "Clanovi steka su: ";
		for (int i = top; i >= 0; i--)
			cout << St[i] << " ";
	}
	else
		cout << "Stack je prazan! " << endl;
}
void Stack::peek() {
	if (!isEmpty()) {
		cout << "Zadnji uneseni clan u stek je: ";
		cout << St[top] << endl;
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
	stack->create();
	system("pause"); system("cls");
	int izbor;
	do {
		izbor = menu();
		if (izbor < 1 || izbor>4) {
			delete stack; stack = nullptr;
			break;
		}
		if (izbor == 1) {
			int key;
			cout << "Unesite vrijednost u stek: "; cin >> key;
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