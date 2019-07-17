// 1. 매개변수의 상수화(모든 함수)
// 2. 메서드의 상수화 (멤버 메서드) : 메서드 안에서 자기가 속한 클래스의 멤버 변수를 수정할 수 없도록 막는 것

#include <iostream>

using namespace std;

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}

	void Deposit(const int d) {// 매개변수의 상수화 
		money += d;
 	}
	void Draw(int d) {
		if (money >= d) {
			money -= d;
			cout << d << "원을 인출했다!!" << endl;
		}
	}
	int ViewMoney() const{// 메서드의 상수화
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