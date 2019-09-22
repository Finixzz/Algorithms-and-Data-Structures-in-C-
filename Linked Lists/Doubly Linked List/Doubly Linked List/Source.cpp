#include<iostream>

using namespace std;

struct node {
	node *prev;
	int key;
	node *next;
};
class Doubly_Llist {
public:
	Doubly_Llist():
		head{nullptr},tail{nullptr}{}
	~Doubly_Llist() {
		node *t1 = head; node *t2 = nullptr;
		while (t1 != nullptr) {
			t2 = t1->next;
			free(t1);
			t1 = t2;
		}
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
	node*head, *tail;
	int index;
};
void Doubly_Llist::set() {
	int n;
	cout << "Unesite koliko zelite unijeti elemenata u listu: "; cin >> n;
	for (int i = 0; i < n; i++) {
		node *temp = new node;
		cout << "Unesite clan: "; cin >> temp->key;
		temp->prev = temp->next = nullptr;
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
}
void Doubly_Llist::print() {
	node *t1 = head;
	cout << "Clanovi liste su: ";
	while (t1 != nullptr) {
		cout << t1->key << " ";
		t1 = t1->next;
	}
	cout << endl;
}
void Doubly_Llist::unesi_clan_na_index() {
	cout << "Unesite index: "; cin >> index;
	node *temp = new node;
	cout << "Unesite novi clan na index: "; cin >> temp->key;
	temp->prev = temp->next = nullptr;
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
			temp->prev = tail;
			tail = temp;
		}
		else {
			t2->next = temp;
			temp->prev = t2;
			temp->next = t1;
			t1->prev = temp;
		}
	}
}
void Doubly_Llist::obrisi_clan_sa_indexa() {
	cout << "Unesite index za brisanje clana sa istog: "; cin >> index;
	node *t1 = head; node *t2 = head->next;
	if (index == 0) {
		free(t1);
		head = t2;
		head->prev = nullptr;
	}
	else {
		for (int i = 0; i < index -1; i++) {
			t1 = t2;
			t2 = t2->next;
		}
		if (t2 == tail) {
			t1->next = nullptr;
			free(t2);
			tail = t1;
		}
		else {
			t1->next = t2->next;
			free(t2);
			t2 = t1->next;
			t2->prev = t1;
		}
	}
}
bool Doubly_Llist::isSorted() {
	node *t1 = head;
	while (t1->next != nullptr) {
		if (t1->key > t1->next->key) {
			return false;
		}
		t1 = t1->next;
	}
	return true;
}
void Doubly_Llist::sortiraj_listu() {
	if (!isSorted()) {
		node *t1 = head; node*t2 = head->next;
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
void Doubly_Llist::unesi_clan_u_sortiranu_listu(){
	sortiraj_listu();
	node *temp = new node;
	cout << "Unesite novi clan u sortiranu listu: "; cin >> temp->key;
	temp->prev = temp->next = nullptr;
	if (temp->key < head->key) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else if (temp->key > tail->key) {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	else {
		node *t1 = head; node*t2 = nullptr;
		while (temp->key > t1->key) {
			t2 = t1;
			t1 = t1->next;
		}
		t2->next = temp;
		temp->prev = t2;
		temp->next = t1;
		t1->prev = temp;
	}
}
void Doubly_Llist::obrisi_duplikate() {
	sortiraj_listu();
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

	Doubly_Llist l;

	system("pause");
	return 0;
}