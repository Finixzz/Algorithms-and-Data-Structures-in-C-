#include<iostream>

using namespace std;

void set(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << ". clan: "; cin >> A[i];
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
		if (A[i] > max)
			max = A[i];
	}
	return max;
}
void count_sort(int *A, int n) {
	int max = getMax(A, n) + 1;
	int *C = new int[max];
	for (int i = 0; i < max; i++) {
		C[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		C[A[i]]++;
	}
	int j = 0;
	for (int i = 0; i < max; i++) {
		while (C[i]> 0) {
			A[j] = i;
			C[i]--;
			j++;
		}
	}
	delete[]C; C = nullptr;
}
int main() {

	int n;
	cout << "Unesite broj clanova niza: "; cin >> n;
	int *A = new int[n];
	set(A, n);
	count_sort(A, n);
	print(A, n);

	system("pause");
	return 0;
}