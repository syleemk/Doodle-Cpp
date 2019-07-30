/*
������ ����ȯ
����� ����ȯ

Item��ü�� int������ ��ȯ�ϱ�
*/

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	//��ȯ������ ���� explicitŰ���带 ���� ������ ����ȯ�� ���� �� �ִ�.
	Item(int num) : num(num) {//��ȯ ������ (�����ڰ� int���� Item���� ��ȯ���ִ� "����"���� ���ְ� ����)
		cout << "Item(int)" << endl;
	}
	Item(string name) : name(name) {
		cout << "Item(string)" << endl;
	}
	Item(int num, string name) : num(num), name(name) {
		cout << "Item(int, string)" << endl;
	}

	void print() {
		cout << num << " : " << name << endl;
	}

	//explicitŰ���带 �ٿ��ָ�, �ݵ�� ��������θ� ����ȯ�� �����ϴ�.
	//����ȯ �������� �����ε� (�ణ ����� �ٸ�)
	explicit operator int() const {//int�� �� ��ȯ�ϴ� ������ �����ε� / constŰ���带 ���� ����ȯ �ϴ� ���� ��ü ��ü�� ���빰�� �ٲ��� ������ ����
		return  num;
	}
	
	//string������ ����ȯ ������ �����ε�
	explicit operator string() const {
		return to_string(num) + " : " + name;
	}

private:
	int num;
	string name;
};

void println(string s) {
	cout << s << endl;
}

void println(int n) {
	cout << n << endl;
}

int main() {
	Item i1 = Item(1);
	Item i2(2);
	Item i3 = 3;
	i3 = 3; 
	Item i4 = (Item)4;

	Item i5 = string("stone");

	Item i6(1, "grass");
	Item i7 = { 2, "dirt" };
	i7 = { 2, "dirt" }; 
	Item i8{ 3,"wood" };

	int itemNum1 = (int)i8; //������
	int itemNum2 = (int)i7; //����� (����ȯ ������ �����ε��� ������ ����� �Ѵ� ����)
	cout << itemNum1<< endl;
	cout << itemNum2 << endl;

	println((string)i8);//����� ����ȯ
	println((int)i8);//������ ����ȯ (�ָ��� ��쿡�� ��������� ����ȯ �������)

	//������ ��ȯ�� �ƿ� ���ƹ��� �� ����
}