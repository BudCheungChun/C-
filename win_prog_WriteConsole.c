
#include <windows.h>
#include <stdio.h>

void PrintUnicode() {
    wchar_t* aaa = L"一二三四";
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsole(hOut, aaa, wcslen(aaa), NULL, NULL);
/*hOut變量相等於Linux輸入、輸出、錯誤文件描述符(0,1,2)中的1,不過windows中的輸出文件描述符不固定,要用HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE)去拎個輸出文件描述符
  文件描述符有3個分別是 : 
  STD_OUTPUT_HANDLE
  STD_INPUT_HANDLE
  STD_ERROR_HANDLE
*/
}

int main() {
    PrintUnicode();
    return 0;
}

/*
#include<stdio.h>

int main(){
    printf("一二三四五");
    return 0;
}
*/

