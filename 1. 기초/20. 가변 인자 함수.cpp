#include <iostream>
#include <algorithm>
#include <cstdarg>

using namespace std;

// 앞에서부터 최소 1개 이상은
// 고정 인자여야 한다.
void MyPrintf(string s, ...)
{
    // 참조자 선언
    va_list vlist;

    // va_start 에 시작 위치를
    // 전달해야 하기 때문이다.
    //
    // va_arg 는 s 다음 인자부터 시작하게 된다.
    va_start(vlist, s);

    int start = 0;
    size_t n = count(s.begin(), s.end(), '%');

    for (int i = 0; i < n; ++i)
    {
        int pos = s.find('%', start);

        cout << s.substr(start, pos - start);

        // va_arg 가 호출되면 내부에서는
        // 알아서 다음 인자를 가리키게 된다.
        if (s[pos + 1] == 'd')      cout << va_arg(vlist, int);
        // float => double
        else if (s[pos + 1] == 'f') cout << va_arg(vlist, double);
        // char, short => int 로 자동 승격된다.
        else if (s[pos + 1] == 'c') cout << va_arg(vlist, char);
        else if (s[pos + 1] == 's') cout << va_arg(vlist, const char*);

        start = pos + 2;
    }

    cout << s.substr(start, s.length() - start);

    // 참조자 해제
    va_end(vlist);
}

int main(int argc, char* argv[])
{
    MyPrintf("%d%s%f%c\n", 100, "Wow !! ! !!", 3.14, 'A');
    MyPrintf("Hello %d World %s Wow %f Bye %c\n", 100, "Wow !! ! !!", 3.14, 'A');
    MyPrintf("%d Hello %s World %f Wow %c Bye\n", 100, "Wow !! ! !!", 3.14, 'A');

    return 0;
}
