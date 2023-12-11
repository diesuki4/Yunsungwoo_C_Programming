/*
 * https://thrillfighter.tistory.com/383
 */
#include <iostream>

using namespace std;

// 정확한 계산 방법은 사실 잘 모르겠다..
// 확실한 건 CPU는 4바이트 혹은 8바이트씩 읽는 게 효율적이기 때문에
// 빈 공간을 넣어 패딩을 추가한다는 것이다.
struct AAA
{
    char c1;    // 1
    int i;      // 4
    short s1;   // 2
    float f;    // 4
    double d;   // 8
    char c2;    // 1
    long l;     // 4
    short s2;   // 2
    long double ld;     // 8
    short s3;   // 2
    unsigned long long int ulli;    // 8
    char c3;    // 1
    short s4;    // 1
    char c4;    // 1
    char c5;    // 1
    char c6;    // 1
};

// I/O 바운드한 네트워크 환경에서는
// 부하를 줄이기 위해 임의로 패딩을 빼기도 한다.
// 
// 단, 이때는 CPU 가 어느 멤버에 대해 2번만 읽어도 될 것을
// 오프셋이 꼬여서 3번을 읽어야 하는 일이 생긴다.
#pragma pack(push, 1)
struct BBB
{
    char c1;    // 1
    int i;      // 4
    short s1;   // 2
    float f;    // 4
    double d;   // 8
    char c2;    // 1
    long l;     // 4
    short s2;   // 2
    long double ld;     // 8
    short s3;   // 2
    unsigned long long int ulli;    // 8
    char c3;    // 1
    short s4;    // 1
    char c4;    // 1
    char c5;    // 1
    char c6;    // 1
};
#pragma pack(pop)

struct CCC
{
    char carr1[3];  // 3
    short s1;       // 2
    int i;          // 4
    double d;       // 8
    char carr2[18]; // 18
    char carr3[5];  // 5
    short s2;       // 2
};

#pragma pack(push, 1)
struct DDD
{
    char carr1[3];  // 3
    short s1;       // 2
    int i;          // 4
    double d;       // 8
    char carr2[18]; // 18
    char carr3[5];  // 5
    short s2;       // 2
};
#pragma pack(pop)

int main(int argc, char* argv[])
{
    AAA aaa;

    int* pc1 = reinterpret_cast<int*>(&aaa.c1);
    int* pi = reinterpret_cast<int*>(&aaa.i);
    int* ps1 = reinterpret_cast<int*>(&aaa.s1);
    int* pf = reinterpret_cast<int*>(&aaa.f);
    int* pd = reinterpret_cast<int*>(&aaa.d);
    int* pc2 = reinterpret_cast<int*>(&aaa.c2);
    int* pl = reinterpret_cast<int*>(&aaa.l);
    int* ps2 = reinterpret_cast<int*>(&aaa.s2);
    int* pld = reinterpret_cast<int*>(&aaa.ld);
    int* ps3 = reinterpret_cast<int*>(&aaa.s3);
    int* pulli = reinterpret_cast<int*>(&aaa.ulli);
    int* pc3 = reinterpret_cast<int*>(&aaa.c3);
    int* ps4 = reinterpret_cast<int*>(&aaa.s4);
    int* pc4 = reinterpret_cast<int*>(&aaa.c4);
    int* pc5 = reinterpret_cast<int*>(&aaa.c5);
    int* pc6 = reinterpret_cast<int*>(&aaa.c6);

    size_t c1 = (reinterpret_cast<int>(pi) - reinterpret_cast<int>(pc1));
    size_t i = (reinterpret_cast<int>(ps1) - reinterpret_cast<int>(pi));
    size_t s1 = (reinterpret_cast<int>(pf) - reinterpret_cast<int>(ps1));
    size_t f = (reinterpret_cast<int>(pd) - reinterpret_cast<int>(pf));
    size_t d = (reinterpret_cast<int>(pc2) - reinterpret_cast<int>(pd));
    size_t c2 = (reinterpret_cast<int>(pl) - reinterpret_cast<int>(pc2));
    size_t l = (reinterpret_cast<int>(ps2) - reinterpret_cast<int>(pl));
    size_t s2 = (reinterpret_cast<int>(pld) - reinterpret_cast<int>(ps2));
    size_t ld = (reinterpret_cast<int>(ps3) - reinterpret_cast<int>(pld));
    size_t s3 = (reinterpret_cast<int>(pulli) - reinterpret_cast<int>(ps3));
    size_t ulli = (reinterpret_cast<int>(pc3) - reinterpret_cast<int>(pulli));
    size_t c3 = (reinterpret_cast<int>(ps4) - reinterpret_cast<int>(pc3));
    size_t s4 = (reinterpret_cast<int>(pc4) - reinterpret_cast<int>(ps4));
    size_t c4 = (reinterpret_cast<int>(pc5) - reinterpret_cast<int>(pc4));
    size_t c5 = (reinterpret_cast<int>(pc6) - reinterpret_cast<int>(pc5));
    size_t c6 = sizeof(AAA) - c1 - i - s1 - f - d - c2 - l - s2 - ld - s3 - ulli - c3 - s4 - c4 - c5;

    cout << "char = " << sizeof(char) << " (" << c1 << ")" << endl;
    cout << "int = " << sizeof(int) << " (" << i << ")" << endl;
    cout << "short = " << sizeof(short) << " (" << s1 << ")" << endl;
    cout << "float = " << sizeof(float) << " (" << f << ")" << endl;
    cout << "double = " << sizeof(double) << " (" << d << ")" << endl;
    cout << "char = " << sizeof(char) << " (" << c2 << ")" << endl;
    cout << "long = " << sizeof(long) << " (" << l << ")" << endl;
    cout << "short = " << sizeof(short) << " (" << s2 << ")" << endl;
    cout << "long double = " << sizeof(long double) << " (" << ld << ")" << endl;
    cout << "short = " << sizeof(short) << " (" << s3 << ")" << endl;
    cout << "unsigned long long int = " << sizeof(unsigned long long int) << " (" << ulli << ")" << endl;
    cout << "char = " << sizeof(char) << " (" << c3 << ")" << endl;
    cout << "short = " << sizeof(short) << " (" << s4 << ")" << endl;
    cout << "char = " << sizeof(char) << " (" << c4 << ")" << endl;
    cout << "char = " << sizeof(char) << " (" << c5 << ")" << endl;
    cout << "char = " << sizeof(char) << " (" << c6 << ")" << endl << endl;

    cout << "AAA = " << sizeof(BBB) << " (" << sizeof(AAA) << ")" << endl << endl;

    // -------------------

    CCC ccc;

    int* pcarr1 = reinterpret_cast<int*>(&ccc.carr1);
    ps1 = reinterpret_cast<int*>(&ccc.s1);
    pi = reinterpret_cast<int*>(&ccc.i);
    pd = reinterpret_cast<int*>(&ccc.d);
    int* pcarr2 = reinterpret_cast<int*>(&ccc.carr2);
    int* pcarr3 = reinterpret_cast<int*>(&ccc.carr3);
    ps2 = reinterpret_cast<int*>(&ccc.s2);

    size_t carr1 = (reinterpret_cast<int>(ps1) - reinterpret_cast<int>(pcarr1));
    s1 = (reinterpret_cast<int>(pi) - reinterpret_cast<int>(ps1));
    i = (reinterpret_cast<int>(pd) - reinterpret_cast<int>(pi));
    d = (reinterpret_cast<int>(pcarr2) - reinterpret_cast<int>(pd));
    size_t carr2 = (reinterpret_cast<int>(pcarr3) - reinterpret_cast<int>(pcarr2));
    size_t carr3 = (reinterpret_cast<int>(ps2) - reinterpret_cast<int>(pcarr3));
    s2 = sizeof(CCC) - carr1 - s1 - i - d - carr2 - carr3;

    cout << "char[3] = " << sizeof(char[3]) << " (" << carr1 << ")" << endl;
    cout << "short = " << sizeof(short) << " (" << s1 << ")" << endl;
    cout << "int = " << sizeof(int) << " (" << i << ")" << endl;
    cout << "double = " << sizeof(double) << " (" << d << ")" << endl;
    cout << "char[18] = " << sizeof(char[18]) << " (" << carr2 << ")" << endl;
    cout << "char[5] = " << sizeof(char[5]) << " (" << carr3 << ")" << endl;
    cout << "short = " << sizeof(short) << " (" << s2 << ")" << endl << endl;

    cout << "CCC = " << sizeof(DDD) << " (" << sizeof(CCC) << ")" << endl;

    return 0;
}
