#include <iostream>

using namespace std;

class MyClass {
public : // cnt++ 후위증가연산자 : num에다가 먼저 cnt값 넣은 후 하나 증가한다.
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

	cout << "Test #1 : " << endl; // 1 2 3 4 출력
	for (int i = 0; i < 5; i++) {
		obj[i].Check(obj);
	}
	cout << "Test #2 : " << endl;
	for (MyClass &i : obj) {
		i.Check(obj);
	}

	cout << "cnt = " << MyClass::cnt << endl;
}