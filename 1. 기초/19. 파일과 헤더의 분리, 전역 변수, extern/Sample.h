// 중복 포함을 방지한다.
#pragma once

// 다른 파일에서는 헤더를 참고해
// 컴파일을 진행하게 된다.
//
// 존재 여부를 알리는 역할이다.

// 전역 변수와 함수의
// extern 선언
extern int g_num;
int RetVal();

// 매크로
#define PI 3.141592
#define MATH_SQUARE(x) ((x) * (x))

// 구조체, 클래스 정의 등을 담는다.
class Point
{
    int x;
    int y;

public:
    Point(int x, int y);

    void Show();
};
