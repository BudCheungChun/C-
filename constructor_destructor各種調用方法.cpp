#include <iostream>

using namespace std;
class Data {
public:
	int m_num;
	Data() {
		m_num = 0;
		cout << "constructor without parameter" << " m_num = " << m_num << endl;
	}
	Data(int num) {
		m_num = num;
		cout << "constructor within parameter" << " m_num = " << m_num << endl;
	}
	Data(const Data &ob) {
		m_num = ob.m_num;
		cout << "copy constructor" << endl;
	}
	~Data() {
		cout << "destructor" << " m_num = " << m_num << endl;
	}
};

void test01() {
	Data ob1;
	Data ob2 = Data();
	Data ob3(10);
	Data ob4 = Data(20);
	Data ob5 = 30;
}

void test02() {
	Data ob1;
	ob1.m_num = 100;
	Data ob2(ob1);
	Data ob3 = ob1;
	Data ob4 = Data(ob1);
}

int main() {
	test02();
	return 0;
}
