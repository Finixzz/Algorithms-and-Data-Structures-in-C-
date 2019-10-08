#include<iostream>

using namespace std;

void insertInMaxHeap(int *A, int n) {
	int temp = A[n];
	int i = n;
	while (i>1 && temp > A[i / 2]) {
		A[i] = A[i / 2];
		i /= 2;
	}
	A[i] = temp;
}
void insertInMinHeap(int *A, int n) {
	int temp = A[n];
	int i = n;
	while (i > 1 && temp < A[i / 2]) {
		A[i] = A[i / 2];
		i /= 2;
	}
	A[i] = temp;
}
void createHeap(int *A, int n) {
	A[0] = 0;
	for (int i = 1; i < n; i++) {
		cout << "Unesite " << i + 1 << ". clan: "; cin >> A[i];
		if (i > 1) 
			insertInMaxHeap(A, i);
	}
}
void print(int *A, int n) {
	cout << "Heap elements are: ";
	for (int i = 1; i < n; i++) {
		cout << A[i] << " ";
	}
}
int main() {

	int n;
	cout << "Unesite broj elemenata binarne hrpe: "; cin >> n;
	n = n + 1;
	int *A = new int[n];
	createHeap(A, n);
	print(A, n);


	delete[]A; A = nullptr;
	system("pause");
	return 0;
}