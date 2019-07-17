#include <iostream>
/*
int n;
void set() {
	n = 10; // 명시적 전역변수
}

namespace doodle {
	int n;
	void set();
}

namespace google {
	int n;
	void set();
}

int main() {
	::set();
	doodle::set();
	google::set();

	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << google::n << endl;
}

void doodle::set() {
	n = 20;
}

void google::set() {
	n = 30;
}

*/

//namespace 중첩

int n;
void set() {
	n = 10;
}

namespace doodle {
	int n;
	void set() {
		n = 20;
	};

	namespace google {
		int n;
		void set() {
			n = 30;
		};
	}
}

int main() {
	using namespace std;
	using namespace doodle;

	::set();
	doodle::set();
	doodle::set();
	google::set();
		
	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << doodle::google::n << endl;
}
