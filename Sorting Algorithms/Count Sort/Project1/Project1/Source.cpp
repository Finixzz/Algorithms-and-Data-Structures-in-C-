#include<iostream>

using namespace std;

class MyString {
private:
	shared_ptr<char[]>str;
public:
	MyString(const char *_str = "empty") :
		str{ nullptr } {
		str = shared_ptr<char[]>(new char[strlen(_str) + 1], [](int *i) {delete[]i; });
	}
};

int main() {




	system("pause");
	return 0;
}