/*
	���� ����
	private public + protected
	public    : �ܺ����� o �ڽ�Ŭ���� o
	protected : �ܺ����� x �ڽ�Ŭ���� o
	private   : �ܺ����� x �ڽ�Ŭ���� x
*/


#include <iostream>

using namespace std;

class Base {
public: //�θ��� public����� �ڽ��� public ����� ��ӵ� 
	int bPublic;

protected:
	int bProtected;

private:
	int bPrivate;
};

class Derived : public Base { //���� protected�� ����ϸ�, �θ𿡼� public�� ����� protected�� �ٲ����
public :					  //�� ���� ��õ� �������غ��� �� �������� �������� ������� ��õ� ������������ �ٲ����
	int dPublic;			  //�׷� private�� ����ϸ� ��� ���������� �ܺ����� �Ļ�Ŭ�������� ���� �Ѵ� �Ұ����ѵ� ���� ������

	void dFunc() {
		bPublic = 1;
		bProtected = 2;
		//bPrivate :���ٺҰ�
		dPublic = 4;
		dPrivate = 5;
	}
private:
	int dPrivate;
};

int main() {
	Base b;
	Derived d;

	b.bPublic = 1;
	//b.bProtected ���ٺҰ�
	//b.bPrivate ���ٺҰ�

	d.bPublic = 1;
	//d.bProtected ���ٺҰ�
	//d.bPrivate ���ٺҰ�
	d.dPublic = 4;
	//d.dPrivate ���ٺҰ�
}