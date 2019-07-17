// 1. �Ű������� ���ȭ(��� �Լ�)
// 2. �޼����� ���ȭ (��� �޼���) : �޼��� �ȿ��� �ڱⰡ ���� Ŭ������ ��� ������ ������ �� ������ ���� ��

#include <iostream>

using namespace std;

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}

	void Deposit(const int d) {// �Ű������� ���ȭ 
		money += d;
 	}
	void Draw(int d) {
		if (money >= d) {
			money -= d;
			cout << d << "���� �����ߴ�!!" << endl;
		}
	}
	int ViewMoney() const{// �޼����� ���ȭ
		return money;
	}

private:
	int money;
};

int main() {
	Account doodle(200);

	doodle.Deposit(100);
	doodle.Draw(20);

	cout << doodle.ViewMoney() << endl;
}