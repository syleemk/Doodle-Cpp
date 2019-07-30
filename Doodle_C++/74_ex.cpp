#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

class Polygon {
public:
	Polygon() {
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point *points) : nPoints(nPoints) {
		this->points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			this->points[i] = points[i];
		}
	}

	//복사 생성자 구현
	Polygon(const Polygon& a) { //const로 매개변수 받아주는게 좋다(복사생성자니까) 
		nPoints = a.nPoints;
		points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			points[i] = a.points[i];
		}
		cout << "깊은 복사" << endl;
	}

	//이동 생성자 구현 //어차피 지워질객체를 깊은 복사를 하는 대신에, 프로그램 효율을 위해 얕은복사를 해줌
	Polygon(Polygon&& rhs) {
		nPoints = rhs.nPoints;
		points = rhs.points;
		rhs.points = NULL;//원본과의 연결 끊어줘야함

		cout << "얕은 복사" << endl;
	}

	~Polygon() {
		delete[] points;
	}

	//복사 대입 연산자 구현
	Polygon& operator=(const Polygon& a) {
		if (this != &a) { //자기 자신에 대입하는 경우
			nPoints = a.nPoints;

			delete[] points;//이미 메모리 할당되어있는경우 메모리 해제해줘야함
			points = new Point[nPoints];
			for (int i = 0; i < nPoints; i++) {
				this->points[i] = a.points[i];
			}
		}

		cout << "깊은 복사 대입" << endl;

		return *this;
	}

	//이동 대입 연산자 구현
	Polygon& operator=(Polygon&& rhs) {
		if(this != &rhs){
			nPoints = rhs.nPoints;
			delete[] points; //자기 자신에 동적할당 된 데이터 있는 경우 메모리 해제
			points = rhs.points;
			rhs.points = NULL;//연결해제
		}

		cout << "얕은 복사" << endl;
		return *this;
	}

	int GetNPoints() const {
		return nPoints;
	}

	Point *GetPoints()  const {
		if (nPoints == 0) return NULL;
		return points;
	}
private:
	int nPoints;
	Point *points;
};

Polygon getSquare() {
	Point points[4] = { {0,0},{1,0},{1,1},{0,1} };
	Polygon p(4, points);
	return p;
}

int main() {
	Polygon a;
	a = getSquare(); //얕은 객체복사 2회
	Polygon b = a; // 깊은 객체복사 1회
	Polygon c;
	c = a; //깊은 객체복사 1회

	int nPoints = c.GetNPoints();
	Point * points = c.GetPoints();
	for (int i = 0; i < nPoints; i++) {
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
}