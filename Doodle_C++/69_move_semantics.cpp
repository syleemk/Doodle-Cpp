#include <iostream>

using namespace std;

/*
	깊은 복사의 문제점을 해결하기 위해 얉은 복사 사용
	깊은 복사의 문제점 : 어떤 데이터를 복사 할 때마다 변수공간을 새로 할당한다음에 모든 데이터를 복사해줘야함
	객체의 크기가 클 수록 깊은 복사를 할 때마다, 많은 양을 복사해야함

	간혹가다가 깊은 복사가 쓸모가 없어지는 경우가 있음

*/
class String {
public:
	String() {
		cout << "String() : " << this << endl;
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "String(const char*) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	String(const String &rhs) { // 복사 생성자
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}

	~String() {
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;
	}

	String &operator=(const String &rhs) { // 복사대입연산자
		cout << "String &operator=(const String&) : " << this << endl;
		if (this != &rhs) {
			release();
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;
	}

	char* GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
	void SetStrData(const char *str) {
		cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}

private:
	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData allocated : " << (void*)strData << endl;
	}
	void release() {
		delete[] strData;
		if (strData) cout << "strData released : " << (void*)strData << endl;
	}

	char *strData;
	int len;
};

String getName() {
	cout << "===== 2 =====" << endl;
	String res("Doodle");
	cout << "===== 3 =====" << endl;
	return res;
}
/*
	위의 getName()함수에서 res객체는 getName함수에 포함된 객체이기에
	getName()이 리턴되면, 객체가 소멸됨(소멸자가 호출)

	아래 main의 a는 getName의 리턴값을 받음
	res가 리턴값이긴 하지만, 이 res를 리턴해버리면, res는 사라져버림
	그렇다면, a는 어디를 받아야 getName이 리턴하는 값을 받을 수 있느냐

	getName이 리턴되는 순간, 그 리턴값을 받는 새로운 객체가 필요한데,
	그 객체는 이름이 없는 "임시 객체" 임
	임시객체에 res가 복사가 되어서 들어감

	복사생성자가 호출되지 않도록
	res 객체에서 임시객체로 얕은 복사가 이루어지도록 하기 (효율 up)
	임시객체에서 변수a로 얕은 복사가 이루어지도록 하기(효율 up / 원래 깊은복사 2번이나 일어나는데 한번도 안일어나게 바꿈)

	얕은 복사에서 문제점 : 메모리가 2번해제됨
	=> 얕은 복사를 하되, 소멸자는 한번만 호출되도록 하기
	=> 이런 얕은 복사를 위해 c++에서는 이동시멘틱이라는 기능 지원
*/

int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;

	// r-value : 등호의 우변에만 올 수 있는 값 (좌변에는 못오는 값) ( 좌변에 올 수 있으면, 우변에도 올 수 있음)
	// ex ) a=5(가능) 5=a(불가능) a=a(가능)
	//		위의 예에서 a는 좌변에도 올 수 있고, 우변에도 올 수 있으므로 l-value
	//		5는 우변에만 올 수 있으므로 r-value

	// 정리하면, c++에서 모든 값은 r-value 아니면 l-value인데, 우변에만 올 수 있으면 r-value, 좌변에도 올 수 있으면 l-value다
	
	// 임시객체는 메모리상에 공간 할당 된 객체기는 하지만, r-value (이 값에 무엇을 대입해서 수정할 수 없는 값)
	
	// c++에서는 &&(r-value참조자)를 통해 r-value를 참조할 수 있음
	String &&r = getName();
	// 이런 형태를 함수의 매개변수로 집어 넣어주면, r-value를 매개변수로 갖는 함수가 됨

}