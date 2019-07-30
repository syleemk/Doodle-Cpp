/*
	묵시적 형변환
	명시적 형변환

*/

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	Item(int num) : num(num) {//변환 생성자 (생성자가 int형을 Item으로 변환해주는 "역할"까지 해주고 있음)
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
	i3 = 3; //묵시적 형변환
	// 3을 Item으로 변환해주는 과정에서 정의된 변환생성자에 의해 객체가 하나 생기는데, 그게 바로 임시객체, 생성된 임시객체는 이동생성자를 통해 i3로 들어간다.
	Item i4 = (Item)4; // 명시적 형변환

	Item i5 = string("stone");

	Item i6(1, "grass");
	Item i7 = { 2, "dirt" };// 매개변수가 2개 이상인 경우 묵시적 형변환 사용하고 싶을 때 이런 식으로 적어주면 됨
	i7 = { 2, "dirt" }; // c++11(2011년) 문법
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