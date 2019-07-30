/*
	접근 제어
	private public + protected
	public    : 외부접근 o 자식클래스 o
	protected : 외부접근 x 자식클래스 o
	private   : 외부접근 x 자식클래스 x
*/


#include <iostream>

using namespace std;

class Base {
public: //부모의 public멤버는 자식의 public 멤버로 상속됨 
	int bPublic;

protected:
	int bProtected;

private:
	int bPrivate;
};

class Derived : public Base { //만약 protected로 상속하면, 부모에서 public인 멤버를 protected로 바꿔버림
public :					  //즉 위에 명시된 공개수준보다 더 광범위한 공개수준 멤버들을 명시된 공개수준으로 바꿔버림
	int dPublic;			  //그럼 private로 상속하면 어떢함 ㅋㅋㅋㅋㅋ 외부접근 파생클래스에서 접근 둘다 불가능한데 뭐임 ㅋㅋㅋ

	void dFunc() {
		bPublic = 1;
		bProtected = 2;
		//bPrivate :접근불가
		dPublic = 4;
		dPrivate = 5;
	}
private:
	int dPrivate;
};

int main() {
	Base b;
	Derived d;

	b.bPublic = 1;
	//b.bProtected 접근불가
	//b.bPrivate 접근불가

	d.bPublic = 1;
	//d.bProtected 접근불가
	//d.bPrivate 접근불가
	d.dPublic = 4;
	//d.dPrivate 접근불가
}