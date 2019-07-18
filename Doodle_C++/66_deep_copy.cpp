#include <iostream>

using namespace std;

/*
int main() {
	int * a = new int(5);
	int * b = new int(3);

	//a = b; // ���� ���� (������ ����) (����Ű�� �ּҰ��� �������ִ� ��)
	*a = *b; // ���� ���� (���� ����) (����Ű�� �� ��ü�� ����)
	// call by value , call by reference ����
	// ����Ʈ�� �ִ� ��� ������ ���� ������ ���� ���� ����

	delete a; // ���⼭ �̹� �޸� ���� ����
	delete b; // ������ �� �޸𸮸� �� �����Ϸ��� ���� ������ ������

}
*/

//��ü���� �����Ҵ��� �� ��쿡, ��ü�� �����ϴµ�, �ǵ�ġ �ʰ� ���� ���簡 �Ͼ�� ���̽��� ����
//��ü���� ��������� �����Ͱ� �ִ� ���

class String {
public:
	String() {
		strData = NULL; // �����Ͱ� �ƹ� �͵� ����Ű�� �ʴ� ���� ǥ��
		len = 0;
	}
	String(const char * str) {
		//strData = str; // �̷��� �ϸ� ���� ���� �Ͼ�ϱ� �ϸ� �ȵ�
		len = strlen(str);
		strData = new char[len+1]; // �����ϱ� ���� strData�� �����Ҵ� �������, null ���ڸ� ����� len +1 ��ŭ �Ҵ�
		strcpy(strData, str); // ���� ���� (���� ����)
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
	char * strData; // ���ڿ� ���� �Ҵ��� ��, �� �ּҸ� ���⿡ ����
	int len; // ���ڿ� ���� ����
};


int main() {
	String s;
}