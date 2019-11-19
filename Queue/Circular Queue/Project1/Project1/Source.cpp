#include<iostream>

using namespace std;

class Queue {
	int front, rear, size;
	int *Q;
public:
	Queue():
		front{0},rear{0},size{0}{}
	~Queue() {
		delete[]Q; Q = nullptr;
	}

	void create();
	void enqueue(int key);
	void dequeue();
	int isEmpty();
	int isFull();
	void print();
};
void Queue::create() {
	cout << "Unesite velicinu cirkularnog reda: "; cin >> size;
	Q = new int[size];
}
void Queue::enqueue(int key) {
	if (!isFull()) {
		rear = (rear + 1) % size;
		Q[rear] = key;
		cout << "Clan " << Q[rear] << " unesen u red! " << endl;
	}
	else
		cout << "Red je popunjen! " << endl;
}
void Queue::dequeue() {
	if (!isEmpty()) {
		front = (front + 1) % size;
		cout << "Clan " << Q[front] << " izbrisan iz reda! " << endl;

	}
	else
		cout << "Red je prazan! " << endl;
}
int Queue::isEmpty() {
	return front == rear;
}
int Queue::isFull() {
	return front == (rear + 1) % size;
}
void Queue::print() {
	if (!isEmpty()) {
		cout << "Clanovi reda su: ";
		int i=(front + 1) % size;
		do {
			cout << Q[i] << " ";
			i = (i + 1) % size;
		} while (i != (rear + 1) % size);
		cout << endl;
	}
	else
		cout << "Red je prazan! " << endl;
}

int menu() {
	int izbor;
	do {
		cout << "----------------\n";
		cout << "      MENU\n";
		cout << "----------------\n";
		cout << "1) Enqueue\n";
		cout << "2) Dequeue\n";
		cout << "3) Print Queue\n";
		cout << "4) Kraj\n";
		cout << "----------------\n";
		cout << "Unesite izbor: "; cin >> izbor;
		return izbor;
	} while (1);
}

int main() {

	int izbor;
	Queue *queue = new Queue;
	queue->create();
	system("pause"); system("cls");
	do {
		izbor = menu();
		if (izbor == 4) {
			delete queue; queue = nullptr;
			break;
		}
		if (izbor == 1) {
			int key;
			cout << "Unesite vrijednost u red: "; cin >> key;
			queue->enqueue(key);
			system("pause"); system("cls");
		}
		if (izbor == 2) {
			queue->dequeue();
			system("pause"); system("cls");
		}
		if (izbor == 3) {
			queue->print();
			system("pause"); system("cls");
		}
	} while (1);


	system("pause");
	return 0;
}