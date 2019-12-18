#include<iostream>

using namespace std;

void set(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << ". clan niza: "; cin >> A[i];
	}
}

void print(int *A, int n) {
	cout << "Clanovi niza su: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void shell_sort(int *A, int n) {
	int temp, j;
	for (int gap = n / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i < n; i++) {
			temp = A[i];
			j = i - gap;
			while (j >= 0 && A[j] > temp) {
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = temp;
		}
	}
}

int main() {

	int n;
	cout << "Unesite broj clanova niza: "; cin >> n;
	int *A = new int[n];
	set(A, n);
	shell_sort(A, n);
	print(A, n);
	delete[]A; A = nullptr;
	system("pause");
	return 0;
}