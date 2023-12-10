#include <iostream>

using namespace std;

/*
 * 매크로 함수
 * 
 * 호출과 반환 과정 없이
 * 인라인 함수처럼 동작하기 때문에 빠르다.
 * 
 * 템플릿처럼 자료형에 따라 별도의 함수를 만들지 않아도 된다.
 * 
 * 정의하기가 까다롭다.
 * 
 * 전처리 후의 컴파일 오류를 띄우기 때문에
 * 디버깅하기가 어렵다.
 */

#define DIFF_ABS(X, Y) ((X) > (Y) ? (X) - (Y) : (Y) - (X))
// 잘못된 매크로 함수
#define DIFF_ABS_WRONG(X, Y) ((a) > (b) ? (a) - (b) : (b) - (a))

// #김이박 => "김이박" 으로 치환된다.
#define MAKE_STRING(A, B) #A"의 직업은 "#B"입니다."
// "김이박" 이 그대로 치환된다.
#define MAKE_STRING_BETTER(A, B) A"의 직업은 "B"입니다."
// 잘못 동작하는 매크로 함수
#define MAKE_STRING_NOT_WORK(A, B) "A의 직업은 B입니다."

#define CONNECT(A, B, C) A##B##C

int main(int argc, char* argv[])
{
    cout << DIFF_ABS(3, 5) << endl;
    cout << DIFF_ABS(5.7, 2.2) << endl;

    // 'a': undeclared identifier
    // 'b': undeclared identifier
    // cout << DIFF_ABS_WRONG(8, 10) << endl;

    // 문자열은 붙여 쓰면 이어 붙일 수 있다.
    const char *str = "THIS " "IS" " ONE" " STINRG";
    cout << str << endl;

    cout << MAKE_STRING(김이박, 의사) << endl;
    // 일반적인 방법이다.
    cout << MAKE_STRING_BETTER("김이박", "의사") << endl;
    // 제대로 동작하지 않는다.
    cout << MAKE_STRING_NOT_WORK("김이박", "의사") << endl;

    int num = 111;

    cout << CONNECT(111, 222, 333) << endl;
    // 아쉽게도 리터럴이 아닌
    // 변수를 이어 붙일 수는 없다.
    // cout << CONNECT(num, num, num) << endl;

    return 0;
}
