#include <windows.h>
#include<stdio.h>

void W_char() {
	wchar_t* pszText = L"ABCCD";//wchar_t 實際上是 unsigned short,2字節2bytes用來裝UTF-16(windows編碼) //"ABCCD"前要加L表示不是單字節字符,而是雙字節數字編碼
    
	int len = wcslen(pszText);//wcslen專用來量度 wchar_t的長度,兩字節兩字節地度,度的是"有效字符",不包'\0',返回值是len
    
	wprintf(L"%s   %d",pszText,len);//print也是用wprintf去印出,前面要加L表示為wchar_t類型
    //char *aaa = "ABCD";
    //wprintf(L"%s   %d %s",pszText,len,aaa);  //段錯誤,不能wchar_t與普通char混合打印
    
    char *aaa = "AAAAA";
	printf("%s",aaa);//可以單獨打印
}

int main() {
    W_char();
    getchar();
	return 0;
}
//output ABCCD   5
