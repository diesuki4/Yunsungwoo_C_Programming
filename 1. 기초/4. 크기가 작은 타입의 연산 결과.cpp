#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    char c1 = 1, c2 = 2;
    short s1 = 1, s2 = 2;
    double d1 = 1.0, d2 = 2.0;

    cout << "Size c1 = " << sizeof(c1) << ", c2 = " << sizeof(c2) << endl;
    cout << "Size s1 = " << sizeof(s1) << ", s2 = " << sizeof(s2) << endl;
    cout << "Size d1 = " << sizeof(d1) << ", d2 = " << sizeof(d2) << endl;

    // <정수 승격>
    // CPU는 int 연산이 가장 빠르고 편하므로,
    // int 보다 작은 정수는 int 로 바꿔서 계산한다.
    //
    // 따라서 연산이 빈번하다면,
    // 범위가 작더라도 int 를 쓰는 게 형 변환 횟수를 줄일 수 있다.
    cout << "Size c1 + c2 = " << sizeof(c1 + c2) << endl;
    cout << "Size s1 + s2 = " << sizeof(s1 + s2) << endl;
    cout << "Size d1 + d2 = " << sizeof(d1 + d2) << endl;

    return 0;
}
