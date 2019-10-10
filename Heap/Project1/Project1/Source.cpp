#include<iostream>

using namespace std;

void insertInMaxHeap(int *A, int n) {
	int temp = A[n];
	int i = n;
	while (i> 1 && temp > A[i / 2]) {
		A[i] = A[i / 2];
		i /= 2;
	}
	A[i] = temp;
}
void insertInMinHeap(int *A, int n) {
	int temp = A[n];
	int i = n;
	while (i > 1  && temp < A[i / 2]) {
		A[i] = A[i / 2];
		i /= 2;
	}
	A[i] = temp;
}
void createHeap(int *A, int n) {
	A[0] = 0;
	for (int i = 1; i < n; i++) {
		cout << "Unesite " << i  << ". clan: "; cin >> A[i];
		if (i >1 ) 
			insertInMaxHeap(A, i);
	}
}
void print(int *A, int n) {
	cout << "Elementi hrpe su: ";
	for (int i = 1; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void Delete(int *A, int n) {
	int x, i, j;
	x = A[1];
	A[1] = A[n];	
	i = 1; j = 2 * i;
	while (j < n-1) {
		if (A[j + 1] > A[j])
			j = j + 1;
		if (A[i] < A[j]) {
			swap(A[i], A[j]);
			i = j;
			j = j * 2;
		}
		else break;
	}
	A[n] = x;
}
void HeapSort(int *A, int n) {
	cout << "Heap sort: ";
	for (int i = n-1 ; i >=1; i--)
		Delete(A, i);
	for (int i = 1; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
int main() {

	int n;
	cout << "Unesite broj elemenata binarne hrpe: "; cin >> n;
	n++;
	int *A = new int[n];
	createHeap(A, n);
	print(A, n);
	HeapSort(A, n);


	delete[]A; A = nullptr;
	system("pause");
	return 0;
}