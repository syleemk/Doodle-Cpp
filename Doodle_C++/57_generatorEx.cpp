#include <iostream>

using namespace std;
/*
//������ : ��� ���� �ʱ�ȭ
//�Ҹ��� : �޸� ����

//���Ҽ�(real, imag)(�Ǽ���, �����)�� �����ϴ� Ŭ���� ������

class Complex {
public:
	Complex() : real(0), imag(0) { } //������ ���
	Complex(double real_, double imag_) : real(real_), imag(imag_) { }

	double GetReal() {
		return real;
	}
	void SetReal(double real_) {
		real = real_;
	}
	double GetImag() {
		return imag;
	}
	void SetImag(double imag_) {
		imag = imag_;
	}
private:
	double real;
	double imag;
};

int main() {
	Complex c1;
	Complex c2 = Complex(2, 3);
	Complex c3(2, 3);

	//�߰�ȣ�� �̿��ؼ� �ʱ�ȭ�� �ϴ� ����� �ִٴ� �� ������ �ϴ� �˱�
	Complex c4 = { 2,3 };
	Complex c5 = Complex{ 2,3 };
	Complex c6{ 2,3 };

	cout << "c1 = " << c1.GetReal() << "," << c1.GetImag() << endl;
	cout << "c2 = " << c2.GetReal() << "," << c2.GetImag() << endl;
	cout << "c1 = " << c3.GetReal() << "," << c3.GetImag() << endl;
}

*/

//�� �� �� ���� Ŭ����
// ������ ���� : � �����ڿ��� �ڱ� Ŭ���� ���� �ٸ� ������ ȣ�� ����
class Time {
public:
	// Time(5) : 5��
	// Time(5,0) : 5��
	// Time(2,37,54) : 2�ð� 37�� 54��
	Time() : h(0), m(0), s(0) {	}
	Time(int s_) : Time() {
		s = s_;
	}
	Time(int m_, int s_) : Time(s_) {
		m = m_;
	}
	Time(int h_, int m_, int s_) : Time(m_, s_) {
		h = h_;
	}

//private:
	int h;
	int m;
	int s;
};

int main() {
	Time t1;
	Time t2(5);
	Time t3(3, 16);
	Time t4(2, 42, 15);

	cout << "t1:" << t1.h << ":" << t1.m << ":" << t1.s << endl;
	cout << "t2:" << t2.h << ":" << t2.m << ":" << t2.s << endl;
	cout << "t3:" << t3.h << ":" << t3.m << ":" << t3.s << endl;
	cout << "t4:" << t4.h << ":" << t4.m << ":" << t4.s << endl;
}