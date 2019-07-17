#include <iostream>

using namespace std;
/*
//생성자 : 멤버 변수 초기화
//소멸자 : 메모리 해제

//복소수(real, imag)(실수부, 허수부)를 저장하는 클래스 만들어보기

class Complex {
public:
	Complex() : real(0), imag(0) { } //생성자 목록
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

	//중괄호를 이용해서 초기화를 하는 방법도 있다는 것 정도만 일단 알기
	Complex c4 = { 2,3 };
	Complex c5 = Complex{ 2,3 };
	Complex c6{ 2,3 };

	cout << "c1 = " << c1.GetReal() << "," << c1.GetImag() << endl;
	cout << "c2 = " << c2.GetReal() << "," << c2.GetImag() << endl;
	cout << "c1 = " << c3.GetReal() << "," << c3.GetImag() << endl;
}

*/

//시 분 초 저장 클래스
// 생성자 위임 : 어떤 생성자에서 자기 클래스 내의 다른 생성자 호출 가능
class Time {
public:
	// Time(5) : 5초
	// Time(5,0) : 5분
	// Time(2,37,54) : 2시간 37분 54초
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