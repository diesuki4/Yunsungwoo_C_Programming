/*
 * Sample.cpp
 */

// cpp 파일에는

#include <iostream>
#include "Sample.h"

using namespace std;

// 실제 전역 변수
int g_num;

// 실제 함수 몸체
int RetVal() { return g_num; }

// 실제 클래스 멤버 함수 구현
// 등을 담는다.
Point::Point(int x, int y) : x(x), y(y) { }

void Point::Show() { cout << "(" << x << ", " << y << ")" << endl; }
