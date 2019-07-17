/*
	연산자 오버로딩은 사칙연산 뿐 아니라
	다양한 연산자들도 오버로딩이 가능하다!!!!
*/


#include <iostream>

using namespace std;

class Vector2 {// get set함수 만드는데, 이러한 함수같은 경우 Set은 안만드는게 좋음 / 하나의 원소만 변경하는건 넌센스
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const; // get함수는 const로 해주는게 좋음
	float GetY() const; // const로 선언할 수 있는 모든 메서드는 const로 선언해주는게 좋다

	//Vector2를 반환하고 Vector2 형식의 매개변수를 받는 메서드가 있을때,
	//그 메서드의 이름을 operator+로 주게 되면, 메서드 형식으로 쓸 수도 있고, 그냥 연산자처럼 쓸 수도 있다!!
	Vector2 operator+(const Vector2 rhs) const;  // 연산자 오버로딩 / operator은 예약어임 철자 틀리면 안됨!!
	Vector2 operator-(const Vector2 rhs) const;
	float operator*(const Vector2 rhs) const;
	Vector2 operator/(const float rhs) const;
	Vector2 operator*(const float rhs) const; // 벡터 나누기 실수는 가능 (5로 나누는 건 1/5 곱한것과 같음)
	// 벡터 나누기 벡터는 안됨 ㅋㅋ

private:
	float x;
	float y;
};

// 편의상 위에 연산자 오버로딩을 멤버연산자
// 아래걸 비멤버 연산자로 지칭 (매개변수가 2개 ㅋㅋ)
Vector2 operator*(const float a, const Vector2 b) {// 함수에는 const 못 붙임, const 멤버 메서드의 목적 자체가, 자신이 속한 클래스의 멤버 변수를 변경하지 못하게 하기위한 것
													// 따라서 멤버 메서드가 아니면 const 못붙임
	return Vector2(a * b.GetX(), a* b.GetY());
}



int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c = a * 3;
	c = 3 * a; // 이거는 비멤버연산자를 의미함 , 얘는 아래처럼 메서드 형식으로 못쓴다. 이 operator은 멤버가 아니기 때문
	Vector2 c2 = a.operator+(b); // 이런 메서드 형식으로도 쓸 수 있음
	Vector2 c3 = a / 2; // 오류 안난다!!!
	Vector2 c4 = a - b;
	float c5 = a * b;

	// C의 기본자료형은 객체가 아니므로 연산자 오버로딩 불가능
	//Vector c6 = (1.6f).operator*(a); // double형에 f붙여주면 float로 캐스팅됨

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c.GetX() << ", " << c.GetY() << endl;
	cout << c2.GetX() << ", " << c.GetY() << endl;
	cout << c3.GetX() << ", " << c3.GetY() << endl;
	cout << c4.GetX() << ", " << c4.GetY() << endl;
	cout << c5 << endl;
}

Vector2::Vector2() :x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {} // 무조건 후반부만 뒤로 밀어주면 됨

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

Vector2 Vector2::operator+(const Vector2 rhs) const {
	return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2 rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
	return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
	return Vector2(x / rhs, y / rhs);
}

float Vector2::operator*(const Vector2 rhs) const {
	return x * rhs.x + y * rhs.y;
}