/*
 * Func.cpp
 */

// 컴파일러는 파일 단위로 컴파일한다.
// 
// 외부에 전역 변수로 선언되어 있다는 것을
// 컴파일러에게 알려야 한다.
extern int num;

void Increment() { ++num; }
int GetNum()     { return num; }

// 함수의 static 도
// 다른 파일에서의 호출을 금지한다는 뜻이다.
//
// 외부에서 extern 을 사용할 수 없다.
static void Reset() { num = 0; }
