/*
	override : 우선하다 ( A override B : A가 B를 우선한다.
	overwrite : 덮어쓰다
*/

#include <iostream>

using namespace std;


//이름이 같은 상속 받아온 멤버와, 고유 멤버가 있을 때, 부모클래스보다 자기 고유의 멤버가 "우선한다"
class Base {
public:
	int a = 10;
	void Print() {
		cout << "From Base!!" << endl;
	}
};

class Derived : public Base {
public:
	int a = 20;
	void Print() {
		cout << "From Derived!!!!" << endl;
	}
};

int main() {
	Base b;
	Derived d;

	cout << b.a << endl;
	cout << d.a << endl; //상속 받아온 a가 아닌 파생클래스의 a를 우선적으로 출력

	cout << d.Base::a << endl; //명시적으로 어느 class소속인지 명시해주면 출력가능
	cout << d.Derived::a << endl;

	d.Print();
	d.Base::Print();
	d.Derived::Print();
}