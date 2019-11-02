#include<iostream>

using namespace std;

void set(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << ". clan u listu: "; cin >> A[i];
	}
}
void print(int *A, int n) {
	cout << "Clanovi niza su: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
bool isSorted(int *A, int n) {
	for (int i = 0; i < n-1; i++) {
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}
void selection_sort(int *A, int n) {
	if (!isSorted(A, n)) {
		int k;
		for (int i = 0; i < n - 1; i++) {
			for (int j = k = i; j < n; j++) {
				if (A[j] < A[k])
					k = j;
			}
			swap(A[i], A[k]);
		}
	}
}

int main() {

	int n;
	cout << "Unesite broj clanova niza: "; cin >> n;
	int *A = new int[n];
	set(A, n);
	selection_sort(A, n);
	print(A, n);


	system("pause");
	return 0;
}