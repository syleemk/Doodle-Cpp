#include <iostream>

using namespace std;

/*
int main() {
	int * a = new int(5);
	int * b = new int(3);

	//a = b; // 얉은 복사 (참조만 복사) (가리키는 주소값만 변경해주는 것)
	*a = *b; // 깊은 복사 (값을 복사) (가리키는 값 자체를 복사)
	// call by value , call by reference 느낌
	// 포인트가 있는 모든 변수는 값과 참조에 대한 문제 있음

	delete a; // 여기서 이미 메모리 해제 해줌
	delete b; // 해제가 된 메모리를 또 해제하려면 원래 에러가 나야함

}
*/

//객체에서 동적할당을 한 경우에, 객체를 복사하는데, 의도치 않게 얉은 복사가 일어나는 케이스가 생김
//객체에서 멤버변수로 포인터가 있는 경우

class String {
public:
	String() {
		strData = NULL; // 포인터가 아무 것도 가리키지 않는 것을 표현
		len = 0;
	}
	String(const char * str) {
		//strData = str; // 이렇게 하면 얉은 복사 일어나니까 하면 안됨
		len = strlen(str);
		strData = new char[len+1]; // 복사하기 전에 strData를 동적할당 해줘야함, null 문자를 고려해 len +1 만큼 할당
		strcpy(strData, str); // 깊은 복사 (값을 복사)
	}

	~String() {
		delete[] strData;
	}

	char * GetStrData() const{
		return strData;
	}

	int GetLen() const {
		return len;
	}

private:
	char * strData; // 문자열 동적 할당한 후, 그 주소를 여기에 저장
	int len; // 문자열 길이 저장
};


int main() {
	String s;
}