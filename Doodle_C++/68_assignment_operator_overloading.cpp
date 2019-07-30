#include <iostream>

using namespace std;


class String {
public:
	String() {
		cout << "String() ������ ȣ��" << endl;
		strData = NULL;
		len = 0;
	}
	String(const char * str) {
		cout << "String(const char *) ������ ȣ��" << endl;
		len = strlen(str);
		strData = new char[len + 1]; //null ���� ����� len+1��ŭ �Ҵ�
		cout << "strData �Ҵ� : " << (void *)strData << endl;
		strcpy(strData, str); // ���� ����
	}

	//���� ������
	String(const String &rhs) {
		cout << "String(String &rhs) ������ ȣ��" << endl;
		strData = new char[rhs.len + 1]; //null ���� ����� len+1��ŭ �Ҵ�
		cout << "strData �Ҵ� : " << (void *)strData << endl;
		strcpy(strData, rhs.strData); // ���� ����
		len = rhs.len; // ���� ����

	}

	~String() {
		cout << "~String() �Ҹ��� ȣ��" << endl;
		delete[] strData;
		cout << "strData ������ : " << (void*)strData << endl;
		strData = NULL;
	}

	String& operator=(const String & rhs) {//���۷����� ��������ְ� �׳� String rhs�� ���ָ� rhs �Ű����� ��Ʈ�� ��ü�� ���ڰ� ���޵Ǹ�, ��������ڰ� ����Ǿ� ������ �� ����ȴ�. (�������� ����)
										 // ���� ���� ���� ������ �Ҵ�ǹǷ�, call by reference ���־�� �Ѵ�.
	// ��ȯ Ÿ�� ���� ���۷��� ������ �������� �� ����, ��ü�� ������ �� ��, �ӽð�ü�� �����Ǹ鼭 ��ü ���簡 �Ͼ(call by value) �� �������� �����Ҵ� ���� ��
	// ���� reference�� ��ȯ���ָ� �ڿ����� �ٿ���(��ü���� �ٿ���)
		
		if (this != &rhs) { //�ڱ� �ڽ��� �����ϴ� ��� ���� ���� ���� (���⼭ &rhs�� &�� ���۷����� �ƴ϶� �ּҳ�Ÿ���� ����)
			delete[] strData; //���� ������ �ִ� ������ ������ ����������� (�����ڴ� �����Ͱ� �� �����Ǵ� ���� �����Ҵ� �ȵǾ�������, �޼���� �������ִ� ��ü�� �ٷ�Ƿ�)
			cout << "operator= ȣ��" << endl;
			strData = new char[rhs.len + 1]; //null ���� ����� len+1��ŭ �Ҵ�
			cout << "strData �Ҵ� : " << (void *)strData << endl;
			strcpy(strData, rhs.strData); // ���� ����
			len = rhs.len; // ���� ����
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
	String s1("�ȳ�");
	String s2(s1); // ���� ������
	String s3("Hello");
	//s3 = s2; //�̷� ��� ���� ���� �Ͼ ���� ����
	//�̷� ��쿡�� ������ �����ε��� ����� ��
	//��ȯ���� ���� ����ϴµ�, ���͸� ������ ��ȯ�ϴ� ���� ��� void�� �̶� ������ �� ����
	
	// s4 = s3 = s2 �̷� ��쵵 c������ �����ϴ�
	// �̷� �� ����, ���� ������ ��ü�� ��� ���� ��ȯ�ؾ�����, ���� ���� ǥ���� ��������
	// ���� ��ȣ���굵 ���� ��ȯ�ؾ��ϰ�, �� ��ȯ Ÿ���� �ڱ��ڽ��� ���̴�.
	s
	//s3.operator=(s1);
	//�ڱ� �ڽ��� �ڱ� �ڽſ��� �Ҵ��ϴ� ��� ���� ����
	s3 = s2;

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
}