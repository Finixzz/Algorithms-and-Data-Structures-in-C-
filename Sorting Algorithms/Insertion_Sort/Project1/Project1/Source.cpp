#include<iostream>

using namespace std;

void set(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << ". clan niza: "; cin >> A[i];
	}
}
void print(int *A, int n) {
	cout << "Clanovi niza su: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
void selection_sort(int *A, int n) {
	int temp, j;
	for (int i = 1; i < n; i++) {
		temp = A[i];
		j = i - 1;
		while (j > -1 && A[j] > temp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
	}
}
int main() {

	int n;
	cout << "Unesite broj clanova niza: "; cin >> n;
	int *A = new int[n];
	set(A, n);
	selection_sort(A, n);
	print(A, n);

	delete[]A; A = nullptr;
	system("pause");
	return 0;
}