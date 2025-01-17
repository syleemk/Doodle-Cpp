//생성자 : 객체가 생성될 때 자동으로 호출되는 함수
//소멸자 : 객체가 소멸될 때 자동으로 호출되는 함수
//객체가 언제 생성 소멸 되는지

#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() {//리턴값의 자료형 적어주지 않는다 : 생성자
		cout << "생성자가 호출되었다!!" << endl;
	}

	~MyClass() {//소멸자
		cout << "소멸자가 호출되었다!!" << endl;
	}
};

//MyClass globalObj;

void testLocalObj() {
	cout << "testLocalObj함수 시작" << endl;
	MyClass localObj;
	cout << "testLocalObj함수 끝" << endl;
}

int main() {
	cout << "main함수 시작!!" << endl;
	testLocalObj();
	cout << "main함수 끝!!" << endl;
}