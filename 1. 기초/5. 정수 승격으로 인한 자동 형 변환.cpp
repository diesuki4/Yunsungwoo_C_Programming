#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    char c1 = 70, c2 = 80;

    // 형 변환이 총 3번 일어난다.
    // (정수 승격)c1 + (정수 승격)c2
    // c3 = (char) int 결과
    char c3 = c1 + c2;

    cout << (int)c3 << endl;

    return 0;
}
