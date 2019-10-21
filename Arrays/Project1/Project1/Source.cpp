#include<iostream>

using namespace std;

template<class T>
class Array {
public:
	T size;
	T len;
	T *A;

	Array():
		size{ 0 }, len{ 0 }, A{ nullptr }{
		cout << "Unesite velicinu niza: "; cin >> size;
		A = new T[size];
		system("pause"); system("cls");
	}
	~Array() {delete[] A; A = nullptr;}

	void set() {
		cout << "Unesite koliko zelize unijeti elemenata u niz: "; cin >> len;
		for (int i = 0; i < len; i++) {
			cout << "Unesite " << i + 1 << ". clan niza: "; cin >> A[i];
		}
	}
	void print() {
		cout << "Clanovi niza su: ";
		for (int i = 0; i < len; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	void append(int novi_clan) {
		if (len == size)
			cout << "Niz je popunjen! " << endl;
		else {
			A[len] = novi_clan;
			len++;
		}
	}
	void insert(int index, int novi_clan) {
		if (len == size)
			cout << "Niz je popunjen! " << endl;
		else {
			for (int i= len; i > index; i--) {
				A[i] = A[i - 1];
			}
			A[index] = novi_clan;
			len++;
		}
	}

};

int main() {

	Array<int>A;
	A.set();
	A.append(8);
	A.print();

	system("Pause");
	return 0;
}