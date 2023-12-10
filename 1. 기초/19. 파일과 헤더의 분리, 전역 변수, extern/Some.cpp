/*
 * 컴파일러는 cpp 파일만
 * 파일 단위로 컴파일한다.
 * 
 * 포함시키지 않은 헤더에
 * 문제가 있다고 해도
 * 
 * 컴파일 에러가 발생하진 않는다.
 */

// 문제가 있는 헤더
// #include "WrongHeader.h"

void SomeFunc() { return; }

// cpp 파일에서는 문제가 있으면
// 컴파일 에러가 발생한다.
// void SomeFunc() { return 100; }
