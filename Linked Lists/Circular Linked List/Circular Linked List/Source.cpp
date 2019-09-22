#include<iostream>

using namespace std;

struct node {
	int key;
	node *next;
};
class Circular_Llist {
public:
	Circular_Llist() :
		head{ nullptr }, tail{ nullptr }{}
	~Circular_Llist() {
		node *t1 = head; node*t2 = nullptr;
		do {
			t2 = t1->next;
			free(t1);
			t1 = t2;
		} while (t1 != head);
	}

	void set();
	void print();
	void unesi_clan_na_index();
	void obrisi_clan_sa_indexa();
	bool isSorted();
	void sortiraj_listu();
	void unesi_clan_u_sortiranu_listu();
	void obrisi_duplikate();

private:
	node *head, *tail;
	int index;
};
void Circular_Llist::set() {
	int n;
	cout << "Unesite koliko zelite unijeti clanova u listu: "; cin >> n;
	for (int i = 0; i < n; i++) {
		node *temp = new node;
		cout << "Unesite novi clan: "; cin >> temp->key;
		temp->next = nullptr;
		if (head == nullptr) {
			head = temp;
			tail = temp;
			tail->next = head;
		}
		else {
			tail->next = temp;
			tail = temp;
			tail->next = head;
		}
	}
}
void Circular_Llist::print() {
	node *t1 = head;
	cout << "Clanovi liste su: ";
	do {
		cout << t1->key << " ";
		t1 = t1->next;
	} while (t1 != head);
	cout << endl;
}
void Circular_Llist::unesi_clan_na_index() {
	cout << "Unesite index: "; cin >> index;
	node *temp = new node;
	cout << "Unesite novi clan na index: "; cin >> temp->key;
	temp->next = nullptr;
	if (index == 0) {
		temp->next = head;
		head = temp;
		tail->next = head;
	}
	else {
		node *t1 = head; node*t2 = nullptr;
		for (int i = 0; i < index; i++) {
			t2 = t1;
			t1 = t1->next;
		}
		if (t1 == head) {
			tail->next = temp;
			tail = temp;
			temp->next = head;
		}
		else {
			t2->next = temp;
			temp->next = t1;
		}
	}
}
void Circular_Llist::obrisi_clan_sa_indexa() {
	cout << "Unesite index za brisanje clana: "; cin >> index;
	node *t1 = head; node*t2 = head->next;
	if (index == 0) {
		free(t1);
		head = t2;
		tail->next = head;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			t1 = t2;
			t2 = t2->next;
		}
		if (t2 == head) {
			free(t2);
			tail = t1;
			tail->next = head;
		}
		else {
			t1->next = t2->next;
			free(t2);
		}
	}
}
bool Circular_Llist::isSorted() {
	node *t1 = head;
	do {
		if (t1->key > t1->next->key) {
			return false;
		}
		t1 = t1->next;
	} while (t1->next != head);
	return true;
}
void Circular_Llist::sortiraj_listu() {
	if (!isSorted()) {
		node *t1 = head; node*t2 = head->next;
		do {
			do {
				if (t1->key > t2->key) {
					swap(t1->key, t2->key);
				}
				t2 = t2->next;
			} while (t2 != head);
			t1 = t1->next;
			t2 = t1;
		} while (t1 != head);
	}
}
void Circular_Llist::unesi_clan_u_sortiranu_listu() {
	sortiraj_listu();
	node *temp = new node;
	cout << "Unesite novi clan u sortiranu listu: "; cin >> temp->key;
	temp->next = nullptr;
	if (temp->key < head->key) {
		temp->next = head;
		head = temp;
		tail->next = head;
	}
	else if (temp->key > tail->key) {
		tail->next = temp;
		tail = temp;
		temp->next = head;
	}
	else {
		node *t1 = head; node *t2 = nullptr;
		while (temp->key > t1->key) {
			t2 = t1;
			t1 = t1->next;
		}
		t2->next = temp;
		temp->next = t1;
	}
}
void Circular_Llist::obrisi_duplikate() {
	sortiraj_listu();
	node *t1 = head; node*t2 = head->next;
	do {
		if (t1->key == t2->key) {
			t1->next = t2->next;
			free(t2);
			t2 = t1->next;
		}
		else {
			t1 = t2;
			t2 = t2->next;
		}
	} while (t2 != head);
}
int main() {

	Circular_Llist l;

	system("pause");
	return 0;
}