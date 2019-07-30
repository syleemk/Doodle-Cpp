#include <iostream>

using namespace std;

/*
	���� ������ �������� �ذ��ϱ� ���� ���� ���� ���
	���� ������ ������ : � �����͸� ���� �� ������ ���������� ���� �Ҵ��Ѵ����� ��� �����͸� �����������
	��ü�� ũ�Ⱑ Ŭ ���� ���� ���縦 �� ������, ���� ���� �����ؾ���

	��Ȥ���ٰ� ���� ���簡 ���� �������� ��찡 ����

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
	String(const String &rhs) { // ���� ������
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

	String &operator=(const String &rhs) { // ������Կ�����
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
	���� getName()�Լ����� res��ü�� getName�Լ��� ���Ե� ��ü�̱⿡
	getName()�� ���ϵǸ�, ��ü�� �Ҹ��(�Ҹ��ڰ� ȣ��)

	�Ʒ� main�� a�� getName�� ���ϰ��� ����
	res�� ���ϰ��̱� ������, �� res�� �����ع�����, res�� ���������
	�׷��ٸ�, a�� ��� �޾ƾ� getName�� �����ϴ� ���� ���� �� �ִ���

	getName�� ���ϵǴ� ����, �� ���ϰ��� �޴� ���ο� ��ü�� �ʿ��ѵ�,
	�� ��ü�� �̸��� ���� "�ӽ� ��ü" ��
	�ӽð�ü�� res�� ���簡 �Ǿ ��

	��������ڰ� ȣ����� �ʵ���
	res ��ü���� �ӽð�ü�� ���� ���簡 �̷�������� �ϱ� (ȿ�� up)
	�ӽð�ü���� ����a�� ���� ���簡 �̷�������� �ϱ�(ȿ�� up / ���� �������� 2���̳� �Ͼ�µ� �ѹ��� ���Ͼ�� �ٲ�)

	���� ���翡�� ������ : �޸𸮰� 2��������
	=> ���� ���縦 �ϵ�, �Ҹ��ڴ� �ѹ��� ȣ��ǵ��� �ϱ�
	=> �̷� ���� ���縦 ���� c++������ �̵��ø�ƽ�̶�� ��� ����
*/

int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;

	// r-value : ��ȣ�� �캯���� �� �� �ִ� �� (�º����� ������ ��) ( �º��� �� �� ������, �캯���� �� �� ����)
	// ex ) a=5(����) 5=a(�Ұ���) a=a(����)
	//		���� ������ a�� �º����� �� �� �ְ�, �캯���� �� �� �����Ƿ� l-value
	//		5�� �캯���� �� �� �����Ƿ� r-value

	// �����ϸ�, c++���� ��� ���� r-value �ƴϸ� l-value�ε�, �캯���� �� �� ������ r-value, �º����� �� �� ������ l-value��
	
	// �ӽð�ü�� �޸𸮻� ���� �Ҵ� �� ��ü��� ������, r-value (�� ���� ������ �����ؼ� ������ �� ���� ��)
	
	// c++������ &&(r-value������)�� ���� r-value�� ������ �� ����
	String &&r = getName();
	// �̷� ���¸� �Լ��� �Ű������� ���� �־��ָ�, r-value�� �Ű������� ���� �Լ��� ��

}