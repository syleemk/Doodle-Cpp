#include <iostream>

using namespace std;

class MyClass {
public : // cnt++ �������������� : num���ٰ� ���� cnt�� ���� �� �ϳ� �����Ѵ�.
	MyClass() : num(cnt++), ch('\0') { }

	void Check(MyClass * ptr) {
		if (ptr + num == this) {
			cout << num << endl;
		}
	}
	static int cnt;

private:
	int num;
	char ch;
};

int MyClass::cnt = 0;

int main() {
	MyClass obj[5];

	cout << "Test #1 : " << endl; // 1 2 3 4 ���
	for (int i = 0; i < 5; i++) {
		obj[i].Check(obj);
	}
	cout << "Test #2 : " << endl;
	for (MyClass &i : obj) {
		i.Check(obj);
	}

	cout << "cnt = " << MyClass::cnt << endl;
}