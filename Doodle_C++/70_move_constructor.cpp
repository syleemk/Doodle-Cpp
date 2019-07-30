#include <iostream>

using namespace std;

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
	String(const String &rhs) {
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}
	String(String &&rhs) {//매개변수가 r-value / res가 임시객체로 복사되는 동안 이 r-value를 매개변수로 받는 생성자가 호출된다.
		cout << "String(String &&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData; //얕은 복사
		rhs.strData = NULL; //이제 rhs가 리턴해서 소멸해도 strData가 가리켰던 주소는 해제되지 않음
	}


	~String() {
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;
	}

	String &operator=(const String &rhs) {
		cout << "String &operator=(const String&) : " << this << endl;
		if (this != &rhs) {
			release();
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;
	}
	String &operator=(String && rhs) {
		cout << "String &operator=(String&&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData; //얕은 복사
		rhs.strData = NULL; //rhs의 연결 해제
		return *this; //a=b=c같이 연쇄적으로 등호쓰는 문법때문에 return해주는 것
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

int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;
}