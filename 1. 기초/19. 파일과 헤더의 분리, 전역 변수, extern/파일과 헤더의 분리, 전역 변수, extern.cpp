#include <iostream>
#include "Sample.h"

using namespace std;

// 컴파일러는 파일 단위로 컴파일한다.
// 
// 외부에 전역 변수로 선언되어 있다는 것을
// 컴파일러에게 알려야 한다.
//
// 함수에서는 extern 을 생략할 수 있다.
void Increment();
extern int GetNum();

// static 전역 변수, static 함수는
// extern 사용 불가
// 
// extern int ThisFileOnlyNum;
// extern void Reset();

// #include 는 단순히 헤더의 내용을
// 그대로 포함시키는 전처리문이다.
#include "MainHeader1.h"
/*
int main(int argc, char* argv[])
{
    Increment();
*/

    Point point(3, 6);
    point.Show();

    cout << g_num << " " << RetVal() <<  endl;

// <> 대신 "" 을 쓰면
// 상대 경로가 된다.
#include "MainHeader2.h"
/*
    cout << "Num.cpp :: num = " << GetNum() << endl;

    return 0;
}
*/
