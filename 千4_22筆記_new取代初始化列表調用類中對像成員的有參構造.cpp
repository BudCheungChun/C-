#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() {
		cout << "Point的無參構造" << endl;
	}
	Point(int x,int y) {
		this->x = x;
		this->y = y;
		cout << "Point的有參構造" << endl;
	}
	~Point() {
		cout << "Point的析構函數" << endl;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	void show_xy() {
		cout << "x : "<< x <<",y : "<< y <<endl;
	}
};

class Circle {
private:
	Point *middle;//
	int radius;
public:
	Circle() {
		cout << "Circle的無參構造" << endl;
	}
	Circle(int x,int y,int radi) {
		middle = new Point(x,y);//新增一個Point空間,在其內存入x,y
								//把存入了x,y的Point空間地址存入「地址middle」中
		this->radius = radi;
	}
	~Circle() {
		cout << "Circle的析構函數" << endl;
	}
	void extinguish(Point &ob) {
		int x_subtract_difference_square = ((ob.get_x() - middle->get_x()) * (ob.get_x() - middle->get_x()));
		int y_subtract_difference_square = ((ob.get_y()-middle->get_y())*(ob.get_y()-middle->get_y()));
		int radius_square = this->radius*this->radius;
		if (x_subtract_difference_square+ y_subtract_difference_square< radius_square) {
			cout << "點在圓內" << endl;
		}
		if (x_subtract_difference_square + y_subtract_difference_square == radius_square) {
			cout << "點與圓周重疊" << endl;
		}
		if (x_subtract_difference_square + y_subtract_difference_square > radius_square) {
			cout << "點在圓外" << endl;
		}
	}
	
};

int main() {
	Point p1(3,3);
	Circle c1(5,5,20);
	c1.extinguish(p1);

	return 0;
}
