#include <iostream>

using namespace std;

int Func(int* ptr) { return *ptr; }

int main(int argc, char* argv[])
{
    // 배열과 마찬가지로
    // 함수의 이름도 함수의 주소 값이다.
    cout << Func << endl;

    // 함수의 원형에서
    // 이름 => (*변수)
    //
    // 로 바꿔주면 된다.
    // 함수 포인터의 선언은 (소괄호)가 필수이다.
    int (*fptr)(int*) = Func;

    int num = 5;

    cout << fptr(&num) << endl;

    return 0;
}
