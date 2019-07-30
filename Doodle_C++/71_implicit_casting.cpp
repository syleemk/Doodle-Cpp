/*
	������ ����ȯ
	����� ����ȯ

*/

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
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
private:
	int num;
	string name;
};

int main() {
	Item i1 = Item(1);
	Item i2(2);
	Item i3 = 3;
	i3 = 3; //������ ����ȯ
	// 3�� Item���� ��ȯ���ִ� �������� ���ǵ� ��ȯ�����ڿ� ���� ��ü�� �ϳ� ����µ�, �װ� �ٷ� �ӽð�ü, ������ �ӽð�ü�� �̵������ڸ� ���� i3�� ����.
	Item i4 = (Item)4; // ����� ����ȯ

	Item i5 = string("stone");

	Item i6(1, "grass");
	Item i7 = { 2, "dirt" };// �Ű������� 2�� �̻��� ��� ������ ����ȯ ����ϰ� ���� �� �̷� ������ �����ָ� ��
	i7 = { 2, "dirt" }; // c++11(2011��) ����
	Item i8{ 3,"wood" };//

	i1.print();
	i2.print();
	i3.print();
	i4.print();
	i5.print();
	i6.print();
	i7.print();
	i8.print();
}