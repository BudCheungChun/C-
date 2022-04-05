#include <iostream>
#include <string.h>
using namespace std;

class Person {
private:
	char m_name[32];
	int m_age;
public:
	void initPerson(char *name , int age) {
		if (name != NULL) {
			strcpy_s(m_name, name);
		}
		if (age >=0 && age<=100) {
			m_age = age;
		}
	}

	void showPerson(){
		cout << "Name : " << m_name << "  " << "Age : " << m_age << endl;
	}

	void setName(char* name) {
		if (name != NULL) {
			strcpy_s(m_name, name);
		}
	}

	void setAge(int age) {
		if (age >= 0 && age <= 100) {
			m_age = age;
		}
	}

	char* showName() {
		return m_name;
	}

	int showAge() {
		return m_age;
	}
};

int main() {
	Person Eric;
	Eric.initPerson((char *)"Eric",26);
	Eric.showPerson();
	Eric.setAge((int) 99);
	cout << "\nAge : " << (Eric.showAge()) << endl;
	return 0;
}
