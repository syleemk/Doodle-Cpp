#include <iostream>

using namespace std;


class String {
public:
	String() {
		cout << "String() 생성자 호출" << endl;
		strData = NULL;
		len = 0;
	}
	String(const char * str) {
		cout << "String(const char *) 생성자 호출" << endl;
		len = strlen(str);
		strData = new char[len + 1]; //null 문자 고려해 len+1만큼 할당
		cout << "strData 할당 : " << (void *)strData << endl;
		strcpy(strData, str); // 깊은 복사
	}

	//복사 생성자
	String(const String &rhs) {
		cout << "String(String &rhs) 생성자 호출" << endl;
		strData = new char[rhs.len + 1]; //null 문자 고려해 len+1만큼 할당
		cout << "strData 할당 : " << (void *)strData << endl;
		strcpy(strData, rhs.strData); // 깊은 복사
		len = rhs.len; // 깊은 복사

	}

	~String() {
		cout << "~String() 소멸자 호출" << endl;
		delete[] strData;
		cout << "strData 해제됨 : " << (void*)strData << endl;
		strData = NULL;
	}

	String& operator=(const String & rhs) {//레퍼런스로 선언안해주고 그냥 String rhs로 해주면 rhs 매개변수 스트링 객체에 인자가 전달되면, 복사생성자가 실행되어 값들이 다 복사된다. (값에의한 전달)
										 // 따라서 쓸데 없는 공간이 할당되므로, call by reference 해주어야 한다.
	// 반환 타입 또한 레퍼런스 변수로 선언해줄 수 있음, 객체가 리턴이 될 때, 임시객체가 형성되면서 객체 복사가 일어남(call by value) 또 쓸데없는 공간할당 등이 됨
	// 따라서 reference로 반환해주면 자원낭비 줄여줌(객체복사 줄여줌)
		
		if (this != &rhs) { //자기 자신을 대입하는 경우 오류 막기 위해 (여기서 &rhs의 &는 레퍼런스가 아니라 주소나타내는 변수)
			delete[] strData; //원래 가지고 있던 데이터 공간을 해제해줘야함 (생성자는 데이터가 막 생성되는 경우라 공간할당 안되어있지만, 메서드는 생성되있는 객체를 다루므로)
			cout << "operator= 호출" << endl;
			strData = new char[rhs.len + 1]; //null 문자 고려해 len+1만큼 할당
			cout << "strData 할당 : " << (void *)strData << endl;
			strcpy(strData, rhs.strData); // 깊은 복사
			len = rhs.len; // 깊은 복사
		}
		return *this;
	}

	char * GetStrData() const {
		return strData;
	}

	int GetLen() const {
		return len;
	}

private:
	char * strData;
	int len;
};


int main() {
	String s1("안녕");
	String s2(s1); // 복사 생성자
	String s3("Hello");
	//s3 = s2; //이런 경우 얕은 복사 일어나 문제 생김
	//이런 경우에는 연산자 오버로딩을 해줘야 함
	//반환형을 정해 줘야하는데, 저것만 봐서는 반환하는 값이 없어서 void형 이라 생각할 수 있음
	
	// s4 = s3 = s2 이런 경우도 c에서는 가능하다
	// 이런 걸 보면, 대입 연산자 자체가 어떠한 값을 반환해야지만, 위와 같은 표현이 가능해짐
	// 따라서 등호연산도 값을 반환해야하고, 그 반환 타입은 자기자신일 것이다.
	s
	//s3.operator=(s1);
	//자기 자신을 자기 자신에게 할당하는 경우 결함 생김
	s3 = s2;

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
}