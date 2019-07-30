/*
	override : �켱�ϴ� ( A override B : A�� B�� �켱�Ѵ�.
	overwrite : �����
*/

#include <iostream>

using namespace std;


//�̸��� ���� ��� �޾ƿ� �����, ���� ����� ���� ��, �θ�Ŭ�������� �ڱ� ������ ����� "�켱�Ѵ�"
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
	cout << d.a << endl; //��� �޾ƿ� a�� �ƴ� �Ļ�Ŭ������ a�� �켱������ ���

	cout << d.Base::a << endl; //��������� ��� class�Ҽ����� ������ָ� ��°���
	cout << d.Derived::a << endl;

	d.Print();
	d.Base::Print();
	d.Derived::Print();
}