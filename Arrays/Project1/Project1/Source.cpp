#include<iostream>

using namespace std;

template<class T>
class Array {
public:
	int size;
	int len;
	T *A;

	Array():size{ 0 }, len{ 0 }, A{ nullptr }{}
	Array(const Array &src):
		size{ src.size }, len{ src.len }, A{ nullptr }{
		A = new T[size];
		for (int i = 0; i < len; i++)A[i] = src.A[i];
	}
	~Array() {delete[] A; A = nullptr;}

	void create_arr();
	void set();
	void print();
	void append(T novi_clan);
	void insert(int index, T novi_clan);
	void Delete(int index);

	bool l_search(T clan);
	bool b_search(T clan);
	bool rb_search(T clan, int l, int h);
	void reverse();

	Array&operator=(const Array &that);
};
template<class T>
void Array<T>::create_arr() {
	cout << "Unesite velicinu niza: "; cin >> size;
	A = new T[size];
}
template<class T>
void Array<T>::set() {
	create_arr();
	cout << "Unesite koliko zelize unijeti elemenata u niz: "; cin >> len;
	while (len > size) {
		cout << "POGRESAN UNOS! " << endl;
		cout << "Unesite koliko zelize unijeti elemenata u niz: "; cin >> len;
	}
	for (int i = 0; i < len; i++) {
		cout << "Unesite " << i + 1 << ". clan niza: "; cin >> A[i];
	}
}
template<class T>
void Array<T>::print() {
	cout << "Clanovi niza su: ";
	for (int i = 0; i < len; i++)
		cout << A[i] << " ";
	cout << endl;
}
template<class T>
void Array<T>::append(T novi_clan) {
	if (len == size)
		cout << "Niz je popunjen! " << endl;
	else {
		A[len] = novi_clan;
		len++;
	}
}
template<class T>
void Array<T>::insert(int index,T novi_clan) {
	if (len == size)
		cout << "Niz je popunjen! " << endl;
	else {
		for (int i = len; i > index; i--) {
			A[i] = A[i - 1];
		}
		A[index] = novi_clan;
		len++;
	}
}
template<class T>
void Array<T>::Delete(int index) {
	if (index<0 || index>len)
		cout << "Pogresan unos! " << endl;
	else {
		for (int i = index; i < len - 1; i++) {
			A[i] = A[i + 1];
		}
		len--;
	}
}
template<class T>
bool Array<T>::l_search(T clan) {
	for (int i = 0; i < len; i++) {
		if (A[i] == clan)
			return true;
	}
	return false;
}
template<class T>
bool Array<T>::b_search(T clan) {
	int l = 0; int h = len;
	int mid;
	while (l <= h) {
		mid = (l + h) / 2;
		if (clan == A[mid])
			return true;
		else if (clan < A[mid])
			h = mid - 1;
		else if (clan > A[mid])
			l = mid + 1;
	}
	return false;
}
template<class T>
bool Array<T>::rb_search(T clan, int l, int h) {
	static int br = 0;
	if (l <= h) {
		int mid = (l + h) / 2;
		if (clan == A[mid])
			return ++br;
		else if (clan < A[mid])
			return rb_search(clan, l, mid - 1);
		else if (clan > A[mid])
			return rb_search(clan, mid + 1, h);
	}
	return br;
}
template<class T>
void Array<T>::reverse() {
	int i, j;
	for (i = 0, j = len - 1; i < j; i++, j--) {
		swap(A[i], A[j]);
	}
}
template<class T>
Array<T>&Array<T>::operator=(const Array &that) {
	if (this == &that)
		return *this;
	size = that.size;
	len = that.len;
	A = new T[size];
	for (int i = 0; i < len; i++)A[i] = that.A[i];
	return *this;
}
int main() {

	Array<int>A;
	A.set();
	cout << "Clanovi prvog niza su: "; A.print();
	//Usage of copy constructor!
	Array<int>B = A;
	B.reverse();
	cout << "Clanovi drugog niza su: "; B.print();
	//Usage of overloaded = operator!
	Array<int>C;
	C = B;
	C.reverse();
	cout << "Clanovi treceg niza su: "; C.print();

	system("Pause");
	return 0;
}