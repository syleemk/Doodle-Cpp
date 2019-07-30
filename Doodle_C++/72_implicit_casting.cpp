/*
묵시적 형변환
명시적 형변환

Item객체를 int형으로 변환하기
*/

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	//변환생성자 또한 explicit키워드를 통해 묵시적 형변환을 막을 수 있다.
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

	//explicit키워드를 붙여주면, 반드시 명시적으로만 형변환이 가능하다.
	//형변환 연산자의 오버로딩 (약간 방식이 다름)
	explicit operator int() const {//int로 형 변환하는 연산자 오버로딩 / const키워드를 통해 형변환 하는 동안 객체 자체의 내용물은 바뀌지 않음을 보장
		return  num;
	}
	
	//string으로의 형변환 연산자 오버로딩
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

	int itemNum1 = (int)i8; //묵시적
	int itemNum2 = (int)i7; //명시적 (형변환 연산자 오버로딩도 묵시적 명시적 둘다 가능)
	cout << itemNum1<< endl;
	cout << itemNum2 << endl;

	println((string)i8);//명시적 형변환
	println((int)i8);//묵시적 형변환 (애매한 경우에는 명시적으로 형변환 해줘야함)

	//묵시적 변환을 아예 막아버릴 수 있음
}