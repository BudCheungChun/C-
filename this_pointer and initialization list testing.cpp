#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() {
		cout << "(Point)constructor with no parameter" << endl;
	}
	Point(int x,int y) {
		this->x = x;
		this->y = y;
		cout << "(Point)constructor with parameter" << endl;
	}
	~Point() {
		cout << "(Point)destructor" << endl;
	}
	void show_xy() {
		cout << "x : " << this->x << " ,y : " << this->y << endl;
	}
	int get_x() {
		return this->x;
	}
	int get_y() {
		return this->y;
	}

};

class Circle {
private:
	Point middle;
	int r;
public:
	Circle() {
		cout << "(Circle)constructor with no parameter" << endl;
	}
	Circle(int x,int y,int circle_r):middle(x,y), r(circle_r) {
		cout << "(Circle)constructor with parameter" << endl;
	}
	~Circle() {
		cout << "(Circle)destructor" << endl;
	}
	void extinguish(Point &ob) {
		int xx_yy = (ob.get_x() - middle.get_x()) * (ob.get_x() - middle.get_x()) +
			(ob.get_y() - middle.get_y()) * (ob.get_y() - middle.get_y());
		if (r*r == xx_yy) {
			cout << "點在圓上" << endl;
		}
		else if (r * r > xx_yy) {
			cout << "點在圓內" << endl;
		}
		else if (r * r < xx_yy) {
			cout << "點在圓外" << endl;
		}
	}

};

int main() {
	Point p1 = Point(3,15);
	p1.show_xy();
	Circle c1 = Circle(3,5,10);
	c1.extinguish(p1);
	return 0;
}
