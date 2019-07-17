// 연산자 오버로딩
// 벡터
// 멤버 메서드실

/*
	벡터

	실수 처리  : float double
	벡터 : 실수 2개 이상을 묶어서 하나의 벡터를 만듦 / 하지만 우리는 성분이 2개인 벡터만 취급 (예  (2, 3) (-1. 7)
	벡터를 가지고 연산이 가능해짐 (더하기 빼기 곱하기)
	벡터끼리 더하고 빼는건, 벡터의 각 성분끼리 더하거나 빼면 됨

	벡터의 곱 : 실수  * 벡터 / 벡터 * 벡터 가능
	실수 * 벡터 : 벡터의 각 성분에 실수를 곱하면 됨
	벡터 * 벡터 : 2가지 방법이 있음 ( 외적 / 내적 ) : 여기서는 외적은 안다룸

	(2 3) X (-1 7) : 외적
	(2 3) ·(-1 7) : 내적 (점으로 곱해서 도트곱이라고도 함) ; 실수가 결과

	벡터의 내적 결과는 실수가 나온다!!
	(2 3) ·(-1 7) = -2 + 21 = 19 ; 각 성분의 곱끼리 더해서 그 결과값 갖는다.
*/

/*
	멤버 메서드의 선언, 정의 분리하기

	멤버 변수의 선언 정의를 분리하는 경우는 static이 아닌이상 거의 없음
	하지만, 멤버 메서드의 선언 정의를 분리하는 경우는 일반적이다.

	왜냐하면, 함수가 여러개 있고, 함수내에서 다른 함수를 호출하는 경우
	함수의 정의된 순서에 영향을 받기 때문에, 먼저 선언을 다 해주고
	나중에 정의를 해주는게, 순서에 신경쓰지 않고서 오류발생을 맊기에 편하다.
*/

#include <iostream>

using namespace std;
/*
아래 함수의 선언 정의 분리

class Vector2 {// get set함수 만드는데, 이러한 함수같은 경우 Set은 안만드는게 좋음 / 하나의 원소만 변경하는건 넌센스
public:
	Vector2() :x(0),y(0){}
	Vector2(float x, float y) :x(x), y(y) {}

	float GetX() const { return x; } // get함수는 const로 해주는게 좋음
	float GetY() const { return y; }

private:
	float x;
	float y;
};

*/

class Vector2 {// get set함수 만드는데, 이러한 함수같은 경우 Set은 안만드는게 좋음 / 하나의 원소만 변경하는건 넌센스
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const; // get함수는 const로 해주는게 좋음
	float GetY() const;

	static Vector2 Sum(Vector2 a, Vector2 b) {
		return Vector2(a.x + b.x, a.y + b.y);
	}

	Vector2 add(Vector2 rhs) {// rhs == right hand side (우변)
		return Vector2(x + rhs.x, y + rhs.y);
	}

private:
	float x;
	float y;
};



int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	//Vector2 c = a + b; // 연산자 오버로딩 필요
	Vector2 c = Vector2::Sum(a, b);
	Vector2 c2 = a.add(b);

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c.GetX() << ", " << c.GetY() << endl;
	cout << c2.GetX() << ", " << c.GetY() << endl;
}

Vector2::Vector2() :x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {} // 무조건 후반부만 뒤로 밀어주면 됨

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }