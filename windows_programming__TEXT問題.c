#include <stdio.h>


#include <windows.h>


#ifdef UNICODE

typedef wchar_t TCHAR;
#define __TEXT(quote) L##quote

#else

typedef char TCHAR;

#define __TEXT(quote) quote
#endif // UNICODE

int main() {

    TCHAR* aaa = __TEXT("ABCCD");//要加括號
#ifdef UNICODE
    wprintf(L"%s\n", aaa);
#else
    printf("%s\n", aaa);
#endif // UNICODE
    return 0;
}
