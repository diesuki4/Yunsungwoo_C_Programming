/*
 * Num.cpp
 */

 // 전역 변수는 자동으로 0으로 초기화된다.
int num;

// 전역 변수의 static 은
// 다른 파일에서의 접근을 금지한다는 뜻이다.
//
// 외부에서 extern 을 사용할 수 없다.
static int ThisFileOnlyNum = 100;
