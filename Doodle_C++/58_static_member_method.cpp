// static : 정적(붕어빵 틀에 해당되는 멤버들)
// <-> 동적(객체에 포함이 된다고 보면 됨, 각각의 붕어빵 마다 다른 멤버들이 들어가 있는 것)

#include <iostream>

using namespace std;

// 0~1 float R G B

class Color {
public:
	Color() :r(0), g(0), b(0) {};
	Color(float r, float g, float b) : r(r), g(g), b(b) {};

	float GetR() { return r; }
	float GetG() { return g; }
	float GetB() { return b; }

	static Color MixColors(Color a, Color b) {
		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}

private:
	float r;
	float g;
	float b;
};



int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);

	Color purple = Color::MixColors(blue, red);

	cout << " r = " << purple.GetR() << " g = " << purple.GetG() << " b = " << purple.GetB() << endl;
}