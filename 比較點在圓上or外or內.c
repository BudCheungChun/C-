#include <iostream>
#include <string.h>
using namespace std;

class Point {
private:
	int m_x;
	int m_y;
public:
	void setX(int x) {
		m_x = x;
	}
	void setY(int y) {
		m_y = y;
	}
	int showX() {
		return m_x;
	}
	int showY() {
		return m_y;
	}
};

class Circle {
private:
	Point middle;
	int m_r;
public:
	void set_middle(int x,int y) {
		middle.setX(x);
		middle.setY(y);
	}
	void setR(int r) {
		m_r = r;
	}
	void show_middle() {
		cout << "x : " << middle.showX() << "  y : " << middle.showY() << endl;
	}
	int showR() {
		return m_r;
	}
	void compare(Point &p) {
		int distance = (p.showX() - middle.showX()) * (p.showX() - middle.showX())
			+ (p.showY() - middle.showY()) * (p.showY() - middle.showY());
		if (distance > (m_r * m_r)) {
			cout << "The point is outside of the circle" << endl;
		}
		else if (distance = (m_r * m_r)) {
			cout << "The point is on the circle" << endl;
		}
		else {
			cout << "The point is inside the circle" << endl;
		}
	}
};

int main() {
	Circle circle1;
	circle1.set_middle(5,5);
	circle1.setR(10);
	circle1.show_middle();
	cout<<"r of circle1 : "<<circle1.showR()<<endl;

	Point p1;
	p1.setX(20); p1.setY(20);
	circle1.compare(p1);



	return 0;
}
