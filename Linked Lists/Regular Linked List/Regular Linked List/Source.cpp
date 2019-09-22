#include<iostream>	

using namespace std;

struct node {
	int key;
	node *next;
};
class List {
public:
	List() :
		head{ nullptr }, tail{ nullptr }, index{ -1 }{}
	~List() {
		node *t1 = head; node *t2 = nullptr;
		while (t1 != nullptr) {
			t2 = t1->next;
			free(t1);
			t1 = t2;
		}
	}
	void print();
	void set();
	void unesi_clan_na_index();
	void obrisi_clan_sa_indexa();
	bool isSorted();
	void sort();
	void unesi_clan_u_sortiranu_listu();
	void izbaci_duplikate();
private:
	node *head, *tail;
	int index;
};
void List::print() {
	node *t1 = head;
	cout << "Clanovi liste su: ";
	while (t1 != nullptr) {
		cout << t1->key << " ";
		t1 = t1->next;
	}
	cout << endl;
}
void List::set() {
	int n;
	cout << "Unesite koliko zelite unijeti clanova u listu: "; cin >> n;
	for (int i = 0; i < n; i++) {
		node *temp = new node;
		cout << "Unesite clan: "; cin >> temp->key;
		temp->next = nullptr;
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
}
void List::unesi_clan_na_index() {
	cout << "Unesite index: "; cin >> index;
	node *temp = new node;
	cout << "Unesite novi clan na index poziciju: ";
	cin >> temp->key;
	if (index == 0) {
		temp->next = head;
		head = temp;
	}
	else {
		node *t1 = head; node*t2 = nullptr;
		for (int i = 0; i < index; i++) {
			t2 = t1;
			t1 = t1->next;
		}
		if (t1 == nullptr) {
			tail->next = temp;
			tail = temp;
		}
		else {
			t2->next = temp;
			temp->next = t1;
		}
	}
}
void List::obrisi_clan_sa_indexa() {
	cout << "Unesite index za brisanje clana sa istog: "; cin >> index;
	node *t1 = head; node*t2 = head->next;
	if (index == 0) {
		free(t1);
		head = t2;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			t1 = t2;
			t2 = t2->next;
		}
		if (t2 == nullptr) {
			free(t2);
			tail = t1;
			tail->next = nullptr;
		}
		else {
			t1->next = t2->next;
			free(t2);
		}
	}
}
bool List::isSorted() {
	node *t1 = head;
	while (t1->next != nullptr) {
		if (t1->key > t1->next->key) {
			return false;
		}
		t1 = t1->next;
	}
	return true;
}
void List::sort() {
	if (isSorted() == false) {
		node *t1 = head; node *t2 = head->next;
		while (t1 != nullptr) {
			while (t2 != nullptr) {
				if (t1->key > t2->key) {
					swap(t1->key, t2->key);
				}
				t2 = t2->next;
			}
			t1 = t1->next;
			t2 = t1;
		}
	}
}
void List::unesi_clan_u_sortiranu_listu() {
	sort();
	node *temp = new node;
	cout << "Unesite novi clan u sortiranu listu: "; cin >> temp->key;
	temp->next = nullptr;
	if (temp->key < head->key) {
		temp->next = head;
		head = temp;
	}
	else if (temp->key > tail->key) {
		tail->next = temp;
		tail = temp;
	}
	else {
		node *t1 = head; node*t2 = nullptr;
		while (temp->key > t1->key) {
			t2 = t1;
			t1 = t1->next;
		}
		t2->next = temp;
		temp->next = t1;
	}
}
void List::izbaci_duplikate() {
	node *t1 = head; node*t2 = head->next;
	while (t2 != nullptr) {
		if (t1->key == t2->key) {
			t1->next = t2->next;
			free(t2);
			t2 = t1->next;
		}
		else {
			t1 = t2;
			t2 = t2->next;
		}
	}
}
int main() {

	List l;
	//Testiraj ako ti se testira
	system("pause");
	return 0;
}