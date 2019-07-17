// ������ �����ε�
// ����
// ��� �޼����

/*
	����

	�Ǽ� ó��  : float double
	���� : �Ǽ� 2�� �̻��� ��� �ϳ��� ���͸� ���� / ������ �츮�� ������ 2���� ���͸� ��� (��  (2, 3) (-1. 7)
	���͸� ������ ������ �������� (���ϱ� ���� ���ϱ�)
	���ͳ��� ���ϰ� ���°�, ������ �� ���г��� ���ϰų� ���� ��

	������ �� : �Ǽ�  * ���� / ���� * ���� ����
	�Ǽ� * ���� : ������ �� ���п� �Ǽ��� ���ϸ� ��
	���� * ���� : 2���� ����� ���� ( ���� / ���� ) : ���⼭�� ������ �ȴٷ�

	(2 3) X (-1 7) : ����
	(2 3) ��(-1 7) : ���� (������ ���ؼ� ��Ʈ���̶�� ��) ; �Ǽ��� ���

	������ ���� ����� �Ǽ��� ���´�!!
	(2 3) ��(-1 7) = -2 + 21 = 19 ; �� ������ ������ ���ؼ� �� ����� ���´�.
*/

/*
	��� �޼����� ����, ���� �и��ϱ�

	��� ������ ���� ���Ǹ� �и��ϴ� ���� static�� �ƴ��̻� ���� ����
	������, ��� �޼����� ���� ���Ǹ� �и��ϴ� ���� �Ϲ����̴�.

	�ֳ��ϸ�, �Լ��� ������ �ְ�, �Լ������� �ٸ� �Լ��� ȣ���ϴ� ���
	�Լ��� ���ǵ� ������ ������ �ޱ� ������, ���� ������ �� ���ְ�
	���߿� ���Ǹ� ���ִ°�, ������ �Ű澲�� �ʰ� �����߻��� ���⿡ ���ϴ�.
*/

#include <iostream>

using namespace std;
/*
�Ʒ� �Լ��� ���� ���� �и�

class Vector2 {// get set�Լ� ����µ�, �̷��� �Լ����� ��� Set�� �ȸ���°� ���� / �ϳ��� ���Ҹ� �����ϴ°� �ͼ���
public:
	Vector2() :x(0),y(0){}
	Vector2(float x, float y) :x(x), y(y) {}

	float GetX() const { return x; } // get�Լ��� const�� ���ִ°� ����
	float GetY() const { return y; }

private:
	float x;
	float y;
};

*/

class Vector2 {// get set�Լ� ����µ�, �̷��� �Լ����� ��� Set�� �ȸ���°� ���� / �ϳ��� ���Ҹ� �����ϴ°� �ͼ���
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const; // get�Լ��� const�� ���ִ°� ����
	float GetY() const;

	static Vector2 Sum(Vector2 a, Vector2 b) {
		return Vector2(a.x + b.x, a.y + b.y);
	}

	Vector2 add(Vector2 rhs) {// rhs == right hand side (�캯)
		return Vector2(x + rhs.x, y + rhs.y);
	}

private:
	float x;
	float y;
};



int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	//Vector2 c = a + b; // ������ �����ε� �ʿ�
	Vector2 c = Vector2::Sum(a, b);
	Vector2 c2 = a.add(b);

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c.GetX() << ", " << c.GetY() << endl;
	cout << c2.GetX() << ", " << c.GetY() << endl;
}

Vector2::Vector2() :x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {} // ������ �Ĺݺθ� �ڷ� �о��ָ� ��

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }