
#include <iostream>

using namespace std;


class Base {
public:
	void Print() {
		cout << "From Base!!" << endl;
	}
};

class Derived : public Base {
public:
	void Print() {
		cout << "From Derived!!!!" << endl;
	}
};

Derived d;
Base *p = &d; //C++에서는 타입이 달라도 예외적으로, 부모클래스의 포인터가 자식을 가리킬 수 있다

class Derived2 : public Base {

};

//1. 부모를 가리키는 포인터는, 부모를 가리킬 수도 있지만, 자식을 가리킬 수도 있다.
//2. 부모 포인터가 부모를 가리키는지, 자식을 가리키는지 판별하기 어려울 때는, 그냥 부모클래스 멤버를 호출한다.
// == 정적바인딩
int main() {
	Base *b = new Derived();
	b->Print();
	b = new Derived2();
	b->Print();
	delete b;
}