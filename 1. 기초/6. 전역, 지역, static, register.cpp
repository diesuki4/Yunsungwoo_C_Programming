#include <iostream>

using namespace std;

// 전역 변수는 기본적으로
// 0으로 초기화된다.
int globalNum;

// 계속 메모리에 존재하는 전역 변수를
// 레지스터에 둘 수는 없다.
// register int globalNum;

int main(int argc, char* argv[])
{
    // static 지역 변수도
    // 0으로 초기화된다.
    //
    // 할당 시기는 함수의 실행이 아니라,
    // 전역 변수와 동일한 프로그램 시작 시다.
    static int staticLocalNum;

    // 초기화 안 하면
    // 쓰레기 값
    int localNum = 100;

    cout << "전역 변수: " << globalNum << endl;
    cout << "지역 static 변수: " << staticLocalNum << endl;
    cout << "지역 변수: " << localNum << endl;

    // 컴파일러가 변수를 레지스터에
    // 저장할 확률이 높아진다.
    register int regNum = 3;
    register int sum = 0;
    
    for (int i = 0; i < 100000; ++i)
        sum += regNum;

    cout << "Sum: " << sum << endl;

    return 0;
}
