#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

/*
 * MSB(Most Significant Bit)
 *
 * 정수의 부호를 결정한다.
 * 0: 양수, 1: 음수
 *
 * -5
 * [1]0000000 00000000 00000000 00000101
 *
 */

// 1의 보수 = 비트 반전
int OnesComplement(int num) { return ~num; }
// 2의 보수 = 1의 보수 + 1
int TwosComplement(int num) { return OnesComplement(num) + 1; }
// 부호 반전 = 2의 보수 = -1 곱하기
int SignInversion(int num)  { return TwosComplement(num); }

string ToBinary(int num)
{
    return bitset<32>(num).to_string();
}

int main(int argc, char* argv[])
{
    // 5
    int num = 0b101;
    int invNum = SignInversion(num);

    cout << invNum << endl;
    cout << SignInversion(invNum) << endl;

    float f = 0.0001;
    float sum = 0;

    for (int i = 0; i < 1000; ++i)
        sum += f;

    // 소숫점에는 오차가 존재한다.
    cout << sum << endl;

    num = 1;

    // 곱하기 2 보다는 비트 연산자가 더 빠르다.
    cout << (num <<= 1) << endl;
    cout << (num <<= 1) << endl;
    cout << (num <<= 1) << endl;
    cout << (num <<= 1) << endl;

    // 나누기 2 보다는 비트 연산자가 더 빠르다.
    cout << (num >>= 1) << endl;
    cout << (num >>= 1) << endl;
    cout << (num >>= 1) << endl;
    cout << (num >>= 1) << endl;

    // 5
    int num1 = 0b101;
    int num2 = num1 - INT_MAX;

    cout << ToBinary(num1) << endl;
    // LSB는 0으로 채워진다.
    cout << ToBinary(num1 << 2) << endl;
    cout << ToBinary(num1 >> 2) << endl << endl;

    cout << ToBinary(num2) << endl;
    cout << ToBinary(num2 << 2) << endl;
    // MSB는 1로 채워진다.
    cout << ToBinary(num2 >> 2) << endl;

    // unsigned 는 MSB 까지 수를 표현하는 데 사용한다.
    // int 보다 범위가 2배이다.
    unsigned uint = INT_MAX + 2'100'000'000;

    cout << uint << endl;

    return 0;
}
