
#include <windows.h>
#include <stdio.h>

void PrintUnicode() {
    wchar_t* aaa = L"一二三四";
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsole(hOut, aaa, wcslen(aaa), NULL, NULL);
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

