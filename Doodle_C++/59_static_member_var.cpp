//정적 멤버 변수

#include <iostream>

using namespace std;

// 0~1 float R G B

class Color {
public:
	Color() :r(0), g(0), b(0), id(idCounter++) {};
	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {};

	float GetR() { return r; }
	float GetG() { return g; }
	float GetB() { return b; }

	static Color MixColors(Color a, Color b) {
		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}

	static int idCounter; // 정적멤버변수는 클래스안에서 초기화될 수 없음

private:
	float r;
	float g;
	float b;

	int id;
};

int Color::idCounter = 1; // 선언과 정의를 분리 (namespace에서 나옴)


int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);

	Color purple = Color::MixColors(blue, red);

	cout << " r = " << purple.GetR() << " g = " << purple.GetG() << " b = " << purple.GetB() << endl;
}