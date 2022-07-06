//因為要調用類中實例成員的"有參構造",所以要用初始化列表
//用初始化列表,調用類中的實例成員的"有參構造"的筆記,只在 : 
//Circle(int x,int y,int radi):middle(x,y),radius(radi)
//Circle c1
//Circle c2(5,5,20)

//引用的筆記,只在 : 
//void extinguish_reference(Point &ob)
//c2.extinguish_reference(p1);
#include <iostream>
using namespace std;

void Circle_c1();
void Circle_c2();

class Point {
private:
	int x;
	int y;
public:
	Point() {
		cout << "Point的無參constructor" << endl;
	}
	Point(int x, int y) {
		cout << "Point的有參constructor" << endl;
		this->x = x;
		this->y = y;
	}
	~Point() {
		cout << "Point的destructor" << endl;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
};
class Circle {
private:
	Point middle;
	int radius;
public:
	Circle() {
		cout << "Circle的無參constructor" << endl;
	}
	Circle(int x,int y,int radi):middle(x,y),radius(radi) {
		cout << "Circle的有參constructor" << endl;
		//middle.x = x;  //這樣無法賦值middle的x,y
		//middle.y = y;	 //因為middle的x,y是Point middle的private中的東西
		//this->radius=radi;//無法直接賦值
	}
	~Circle() {
		cout << "Circle的destructor" << endl;
	}

	int get_radius() {
		return this->radius;
	}

	void extinguish_reference(Point &ob) {//p1取別名後成&ob
		int x_substract_differance_square = (ob.get_x() - middle.get_x()) * (ob.get_x() - middle.get_x());
		//ob無需解引用,或者說compiler已自動解引用,即可用p1的方法get_x()
		cout << "x差平方 : " << x_substract_differance_square << endl;
		int y_substract_differance_square = (ob.get_y() - middle.get_y()) * (ob.get_y() - middle.get_y());
		cout << "y差平方 : "<< y_substract_differance_square << endl;
		int radius_square = (this->radius) * (this->radius);
		cout << "半徑平方 : " << radius_square << endl;

		if ((x_substract_differance_square + y_substract_differance_square) < radius_square) {
			cout << "點在圓內" << endl;
		}
		if ((x_substract_differance_square + y_substract_differance_square) > radius_square) {
			cout << "點在圓外" << endl;
		}
		if ((x_substract_differance_square + y_substract_differance_square) == radius_square) {
			cout << "點在圓上" << endl;
		}
	}
	void extinguish_pointer(Point *ob) {
		int x_substract_differance_square = (ob->get_x() - middle.get_x()) * (ob->get_x() - middle.get_x());
		cout << "x差平方 : "<< x_substract_differance_square <<endl;
		int y_substract_differance_square = (ob->get_y() - middle.get_y()) * (ob->get_y() - middle.get_y());
		cout << "y差平方 : " << y_substract_differance_square << endl;
		int radius_square = (this->radius) * (this->radius);
		cout << "半徑平方 : "<< radius_square <<endl;

		if ((x_substract_differance_square + y_substract_differance_square) < radius_square) {
			cout << "點在圓內" << endl;
		}
		if ((x_substract_differance_square + y_substract_differance_square) > radius_square) {
			cout << "點在圓外" << endl;
		}
		if ((x_substract_differance_square + y_substract_differance_square) == radius_square) {
			cout << "點在圓上" << endl;
		}
	}
};
int main() {
	
	//Circle_c1();
	Circle_c2 ();
	
	return 0;
}
void Circle_c1() {
	Circle c1;//會先調用Point middle中的無參構造,再調用Circle c1自己的無參構造
			  //但這沒有意義
			  //我要Point middle,Circle c1的有參構造都調用,才能對他們賦值
			  //這就要用到初始化列表,即如下所示 : 
			  //類中 : 
			  //Circle(int x,int y,int radi):middle(x,y),radius(radi){}
			  //實例化時 : 
			  //Circle c1(5,5,20);
	/*
	Point的無參constructor
	Circle的無參constructor
	Circle的destructor
	Point的destructor
	*/
	
	}
void Circle_c2(){
	Point p1(5,8);
	Circle c2(5,5,20);//這就能調用類中實例成員的有參構造
					  
	c2.extinguish_reference(p1);//可以把引用想成compiler會自動解引用的指針
								//把p1(原封不動,無需"&"取地址)存入
								//void extinguish_reference(Point &ob) 即取別名後
								//可ob.get_x()直接使用
								//即compiler自動解引用後的ob,或者說p1在使用get_x()方法
	c2.extinguish_pointer(&p1);

}
