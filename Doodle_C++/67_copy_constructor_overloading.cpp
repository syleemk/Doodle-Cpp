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
		// strData가 포인터인데 이대로 출력해주면 컴파일러가 char형 포인터인지, 문자열인지 모름
		// 그래서 char포인터를 cout에 넘기면, 컴파일러는 이를 문자열로 인식해서 문자열 출력하려함
		// 문자열 들어가있으면 출력하지만, null같은게 들어있으면 오류날 수 있음
		// 그래서 void 포인터 사용한다. 
		// void포인터는 어떤 형식의 포인터 (주소값)도 가질 수 있다.
		// 하지만, 주소가 가리키는 변수의 자료형 이런건 모르기에 값을 바꿀 순 없음
		strcpy(strData, str); // 깊은 복사
	}

	//복사 생성자
	String(const String &rhs) {
		//strData = rhs.strData; // 얕은 복사

		cout << "String(String &rhs) 생성자 호출" << endl;
		strData = new char[rhs.len + 1]; //null 문자 고려해 len+1만큼 할당
		cout << "strData 할당 : " << (void *)strData << endl;
		strcpy(strData,rhs.strData); // 깊은 복사
		len = rhs.len; // 깊은 복사
		
	}

	~String() {
		cout << "~String() 소멸자 호출" << endl;
		delete[] strData;
		cout << "strData 해제됨 : " << (void*)strData << endl;
		strData = NULL;
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
	//String s2 = s1; // == String s2(s1);
	// 이렇게 하면 얉은 복사 일어나서 오류 생김
	// 메모리 소멸될 때 같은 공간 두번 해제되니까

	String s3(s1); // 복사 생성자
	

	cout << s1.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
}