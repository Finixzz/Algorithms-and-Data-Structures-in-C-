#include<iostream>

using namespace std;

struct node {
	node *left;
	int key;
	node *right;
};
class Tree {
public:
	node *root;

	Tree() :
		root{ nullptr } {}
	~Tree() {
		oslobodi_memoriju(root);
	}
	void oslobodi_memoriju(node *x) {
		if (x) {
			oslobodi_memoriju(x->left);
			oslobodi_memoriju(x->right);
			free(x);
		}
	}
	void insert_node(int key) {
		node *x = root;
		node *t = nullptr;
		if (!root) {
			root = new node;
			root->key = key;
			root->left = root->right = nullptr;
			return;
		}
		while (x) {
			t = x;
			if (key == x->key)
				return;
			else if (key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		node*p = new node;
		p->key = key;
		p->left = p->right = nullptr;
		if (t->key > p->key)t->left = p;
		else t->right = p;
	}
	void create_bst() {
		int  key = 0;
		cout << "Za prekid unesite -1!\n";
		while (key != -1) {
			cout << "Unesite vrijednost vrha: "; cin >> key;
			if (key == -1)break;
			insert_node(key);
		}
	}
	node *InPre(node *x) {
		while (x&&x->right) {
			x = x->right;
		}
		return x;
	}
	node* InSucc(node *x) {
		while (x&&x->left)
			x = x->left;
		return x;
	}
	node * delete_node(node *x, int key) {
		node *t = nullptr;
		if (x == nullptr) {
			return 0;
		}
		if (!x->left && !x->right) {
			if (x == root) {
				root = nullptr;
				free(x);
				return 0;
		}

		if (key < x->key)
			x->left=delete_node(x->left, key);
		else if (key > x->key) {
			x->right=delete_node(x->right, key);
		}
		else {
			if (count_height(x->left) > count_height(x->right)) {
				t = InPre(x->left);
				x->key = t->key;
				x->left = delete_node(x->left, t->key);
			}
			else {
				t = InSucc(x->right);
				x->key = t->key;
				x->right = delete_node(x->left, t->key);
				}
			}
		}
		return t;
	}
	void Delete() {
		int key;
		cout << "Unesite vrijednost vrha za brisanje istog: "; cin >> key;
		cout << delete_node(root, key) << endl;
	}
	void print_inorder(node *x) {
		if (x) {
			print_inorder(x->left);
			cout << x->key << " ";
			print_inorder(x->right);
		}
	}
	void print_postorder(node *x) {
		if (x) {
			print_postorder(x->left);
			print_postorder(x->right);
			cout << x->key << " ";
		}
	}
	bool search(node *x,int key) {
		if (x) {
			if (key == x->key)
				return true;
			else if (key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		return false;
	}
	void binary_search() {
		int key;
		cout << "Unesite vrijednost vrha za pretrazivanje binarnog stabla: ";
		cin >> key;
		if (search(root, key)) {
			cout << "Vrh se nalazi u binarnom stablu\n";
		}
		else {
			cout << "Vrh se ne nalazi u binarnom stablu\n";
		}
	}
	int count_height(node *x) {
		static int br = 0;
		static int br2 = 0;
		if (x) {
			count_height(x->left);
			count_height(x->right);
			if (x->left)br++;
			if (x->right)br2++;
			return br > br2 ? br : br2;
		}
		return 0;
	}
};

int main() {

	Tree t;
	t.create_bst();
	t.Delete();
	t.binary_search();

	system("pause");
	return 0;
}