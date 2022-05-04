	/*
	我主要想問啱唔啱的係第32行,strB 指向另一個新開辟開間中的 "AAAA\0",所以指針睇
	落都可以裝string,實質係指向文字常量區的string
	其他都係延伸嘢
	*/

#include <iostream>

using namespace std;
void test01() {
	char strA[] = "test";
	//第5行
	/*
	首先右邊 "test\0" 喺文字常量區開辟一個5個字符的空間
	但因為文字常區不能逐字修改,所以strA依個變量再喺堆區(stack區)開
	辟一個5個字符的空間,compiler 由文字常量區 copy "test\0" 去stack區 
	*/
	char* strB = "test";
	//第12行
	/*
	然後 文字常量區再開辟一個5個字符的空間,放另一個 "test\0" ,strB喺stack
	區開辟一個指針空間,指向文字常量區的 "test\0"
	*/

	strA[0] = 'T';//因為stack區中的 "test\0" 在stack區,所以可以逐字修改
	//strB[0] = 'T';       X
	//因為文字常量區中的 "test\0"在文字常量區,所以無法逐字修改

	//strA = "AAAA";       X
	//因為stack區中的 "test\0"係array所以要用strcpy改
	
	strB = "AAAA";
	/*
	因為strB不過係指向另一個喺文字常量區新開辟的 "AAAA\0",所以strB唔可以逐
	字改,但成個改係無問題
	*/
	cout << "----1----" << endl;
}
#include <string.h>
void test02() {
	char* arr = new char[32];
	/*
	首先arr喺stack區分別開辟arr(char pointer)同一個32byte的空間
	然後arr指向果個32byte空間
	*/
	strcpy(arr,"hello");
	/*
	再嚟就係 喺文字常量區開辟一個6個字符的空間裝"hello\0"
	再用strcpy將"hello\0"逐字經arr放喺arr所指向的32byte空間
	*/
	cout << "----2----" << endl;

	/*
	我主要想問啱唔啱的係第26行,strB 指向另一個新開辟開間中的 "AAAA\0",所以指針睇
	落都可以裝string,實質係指向文字常量區的string
	*/
}

int main() {
	test01();
	test02();
	return 0;
}
