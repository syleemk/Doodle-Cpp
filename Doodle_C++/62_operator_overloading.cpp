/*
	������ �����ε��� ��Ģ���� �� �ƴ϶�
	�پ��� �����ڵ鵵 �����ε��� �����ϴ�!!!!
*/


#include <iostream>

using namespace std;

class Vector2 {// get set�Լ� ����µ�, �̷��� �Լ����� ��� Set�� �ȸ���°� ���� / �ϳ��� ���Ҹ� �����ϴ°� �ͼ���
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const; // get�Լ��� const�� ���ִ°� ����
	float GetY() const; // const�� ������ �� �ִ� ��� �޼���� const�� �������ִ°� ����

	//Vector2�� ��ȯ�ϰ� Vector2 ������ �Ű������� �޴� �޼��尡 ������,
	//�� �޼����� �̸��� operator+�� �ְ� �Ǹ�, �޼��� �������� �� ���� �ְ�, �׳� ������ó�� �� ���� �ִ�!!
	Vector2 operator+(const Vector2 rhs) const;  // ������ �����ε� / operator�� ������� ö�� Ʋ���� �ȵ�!!
	Vector2 operator-(const Vector2 rhs) const;
	float operator*(const Vector2 rhs) const;
	Vector2 operator/(const float rhs) const;
	Vector2 operator*(const float rhs) const; // ���� ������ �Ǽ��� ���� (5�� ������ �� 1/5 ���ѰͰ� ����)
	// ���� ������ ���ʹ� �ȵ� ����

private:
	float x;
	float y;
};

// ���ǻ� ���� ������ �����ε��� ���������
// �Ʒ��� ���� �����ڷ� ��Ī (�Ű������� 2�� ����)
Vector2 operator*(const float a, const Vector2 b) {// �Լ����� const �� ����, const ��� �޼����� ���� ��ü��, �ڽ��� ���� Ŭ������ ��� ������ �������� ���ϰ� �ϱ����� ��
													// ���� ��� �޼��尡 �ƴϸ� const ������
	return Vector2(a * b.GetX(), a* b.GetY());
}



int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c = a * 3;
	c = 3 * a; // �̰Ŵ� ���������ڸ� �ǹ��� , ��� �Ʒ�ó�� �޼��� �������� ������. �� operator�� ����� �ƴϱ� ����
	Vector2 c2 = a.operator+(b); // �̷� �޼��� �������ε� �� �� ����
	Vector2 c3 = a / 2; // ���� �ȳ���!!!
	Vector2 c4 = a - b;
	float c5 = a * b;

	// C�� �⺻�ڷ����� ��ü�� �ƴϹǷ� ������ �����ε� �Ұ���
	//Vector c6 = (1.6f).operator*(a); // double���� f�ٿ��ָ� float�� ĳ���õ�

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c.GetX() << ", " << c.GetY() << endl;
	cout << c2.GetX() << ", " << c.GetY() << endl;
	cout << c3.GetX() << ", " << c3.GetY() << endl;
	cout << c4.GetX() << ", " << c4.GetY() << endl;
	cout << c5 << endl;
}

Vector2::Vector2() :x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {} // ������ �Ĺݺθ� �ڷ� �о��ָ� ��

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