#include <iostream>

using namespace std;

//레퍼런스 변수는 맨 처음 초기화 할 때 이후로, 가리키는 값을 변경할 수 없다.
int main() {
	int a = 10, b = 20, c = 30;
	int *p = &a;
	int &r = b;
	int **pp = &p;
	int * (&rp) = p;

	r = c / *p; // b=3
	rp = &c; // p = c
	**pp = 40; //c=40
	*p = 50; //c=50
	*pp = &a;//p =a
	*rp = 60;//a=60

	cout << a << endl; // 60
	cout << b << endl; // 3
	cout << c << endl; // 50
	cout << *p << endl; // 60
}