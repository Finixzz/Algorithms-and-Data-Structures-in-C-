#include<iostream>	

using namespace std;

class Queue {
private:
	int front, rear, size;
	int *Q;
public:
	Queue():
		front{-1},rear{-1},size{0},Q{nullptr}{}
	~Queue() {
		delete[]Q; Q = nullptr;
	}

	void create();
	void enqueue(int &);
	int dequeue();
	int isEmpty();
	int isFull();
	void print();
	int peek();
	void DeleteQueue();
};
void Queue::create() {
	cout << "Unesite velicinu reda: "; cin >> size;
	Q = new int[size];
}
void Queue::enqueue(int &key) {
	if (!isFull()) {
		rear++;
		Q[rear] = key;
		cout << "Clan " << Q[rear] << " je unesen u red! " << endl;
	}
	else
		cout << "Red je popunjen! " << endl;
}
int Queue::dequeue() {
	front++;
	return Q[front];
}
int Queue::isEmpty() {
	return front == size - 1;
}
int Queue::isFull() {
	return rear == size - 1;
}
void Queue::print() {
	if (!isEmpty()) {
		cout << "Clanovi reda su: ";
		for (int i = front+1; i <= rear; i++) {
			cout << Q[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "Red je prazan! " << endl;
}
void Queue::DeleteQueue() {
	delete[]Q; Q = nullptr;
	front = rear = -1;
	size = 0;
}
int Queue::peek() {
	return Q[front + 1];
}

int menu() {
	int izbor;
	do {
		cout << "-----------------\n";
		cout << "      MENU\n";
		cout << "-----------------\n";
		cout << "1) Enqueue\n";
		cout << "2) Dequeue\n";
		cout << "3) Print\n";
		cout << "4) Peek\n";
		cout << "5) END\n";
		cout << "-----------------\n";
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
		if (izbor < 1 || izbor>4) {
			delete queue; queue = nullptr;
			break;
		}
		if (izbor == 1) {
			int key;
			cout << "Unesite clan u red: ";
			cin >> key;
			queue->enqueue(key);
			system("pause"); system("cls");
		}
		if (izbor == 2) {
			if (queue->isEmpty()) {
				cout << "Red je prazan! " << endl;
			}
			else {
				cout << "Clan "<< queue->dequeue() << " je izbacen iz reda! " << endl;
			}
			system("pause"); system("cls");
		}
		if (izbor == 3) {
			queue->print();
			system("pause"); system("cls");
		}
		if (izbor == 4) {
			if (queue->isEmpty()) {
				cout << "Red je prazan! " << endl;
			}
			else {
				cout <<"Clan "<< queue->peek() <<" je prvi unesen u red! "<< endl;
			}
			system("pause"); system("cls");
		}
	} while (1);

	system("pause");
	return 0;
}