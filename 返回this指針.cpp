#include <iostream>
using namespace std;

class MyCout{
public:
	MyCout& mycout(char *str) {
		cout << str << endl;
		return *this;
	}
};

int main() {
	MyCout ob1;
	ob1.mycout(("ABCD")).mycout("EFGH").mycout("IJKL");
	return 0;
}
