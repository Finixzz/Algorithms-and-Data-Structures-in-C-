#include<iostream>

using namespace std;

void set(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << ". element: "; cin >> A[i];
	}
}
void print(int *A, int n) {
	cout << "Clanovi niza su: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
int getMax(int *A, int n) {
	int max = A[0];
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

struct node {
	int key;
	node *next;
};

void radix_sort(int *A, int n) {
	int max = getMax(A, n);

	for (int i = 1; max / i > 0; i *= 10) {
		node **head = new node*[10];
		node **tail = new node *[10];
		for (int j = 0; j < 10; j++) {
			head[j] = nullptr;
			tail[j] = nullptr;
		}
		for (int j = 0; j < n; j++) {
			node *t = new node;
			t->key = A[j];
			t->next = nullptr;
			if (head[(t->key / i) % 10] == nullptr) {
				head[(t->key / i) % 10] = t;
				tail[(t->key / i) % 10] = t;
			}
			else {
				tail[(t->key / i) % 10]->next = t;
				tail[(t->key / i) % 10] = t;
			}
		}

		int k = 0;
		for (int j = 0; j < 10; j++) {
			while (head[j] != nullptr) {
				A[k] = head[j]->key;
				k++;
				head[j] = head[j]->next;
			}
			delete[]head[j]; head[j] = nullptr;
		}
		delete[]head; head = nullptr;
		delete[]tail; tail = nullptr;
	}
}

int main() {


	int n;
	cout << "Unesite velicinu niza: "; cin >> n;
	int *A = new int[n];
	set(A, n);
	radix_sort(A, n);
	print(A, n);

	delete[]A; A = nullptr;
	system("pause");
	return 0;
}