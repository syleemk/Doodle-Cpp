
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
Base *p = &d; //C++������ Ÿ���� �޶� ����������, �θ�Ŭ������ �����Ͱ� �ڽ��� ����ų �� �ִ�

class Derived2 : public Base {

};

//1. �θ� ����Ű�� �����ʹ�, �θ� ����ų ���� ������, �ڽ��� ����ų ���� �ִ�.
//2. �θ� �����Ͱ� �θ� ����Ű����, �ڽ��� ����Ű���� �Ǻ��ϱ� ����� ����, �׳� �θ�Ŭ���� ����� ȣ���Ѵ�.
// == �������ε�
int main() {
	Base *b = new Derived();
	b->Print();
	b = new Derived2();
	b->Print();
	delete b;
}