// 동적 할당 : 자신이 원할 때 메모리의 공간을 할당 해제 할 수 있는 것
// 프로그램 실행 중에 메모리에 공간을 할당하는 것

#include <iostream>

using namespace std;

/*
int main() {
	int * a = new int(5); //new 다음에 생성자 형태가 나오게 되면, 메모리상에 공간이 만들어지고, 그 공간의 주소값을 반환한다.

	cout << *a << endl;
	cout << a << endl;

	*a = 10;

	cout << *a << endl;
	cout << a << endl;

	delete a; // 메모리 상에 할당된 공간 해제
}
*/


/*

// 배열의 동적할당
// 일반적인 변수를 동적할당하는 경우도 있지만, 대부분 배열을 동적할당 한다.
// 자신이 원하는 길이만큼 할당할 수 있음
int main() {
	int *arr;
	int len;

	cout << "동적할당할 배열 길이 입력 : ";
	cin >> len;

	arr = new int[len]; //이제 arr를 배열처럼 쓸 수 있음

	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}

	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

	//delete arr; // 이렇게 하면 0번째 칸만 메모리 해제해주는 것, 나머지 칸은 남아있음
	delete[] arr; // 이렇게 적어주면, 배열을 해제하라는 표현이라는 것으로 알아들음

}

*/

//객체에 대한 동적 할당

class Vector2 {
public:
	Vector2() : x(0), y(0) {
		cout << this << " : Vector2()" << endl;
	}
	Vector2(const float x, const float y) : x(x), y(y) {
		cout << this << " : Vector2(const float x, const float y)" << endl;
	}

	~Vector2() {
		cout << this << " : ~Vector2()" << endl;
	}

	float GetX() const { return x; }
	float GetY() const { return y; }

private:
	float x;
	float y;
};

int main() {
	Vector2 s1 = Vector2();
	Vector2 s2(3, 2); // == Vector2 s2 = Vector2(3,2);

	Vector2 *d1 = new Vector2();
	Vector2 *d2 = new Vector2(3, 2);

	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

	delete d1;
	delete d2;
}