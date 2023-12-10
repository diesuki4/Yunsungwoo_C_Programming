#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    char str1[] = "Modifiable string";

    // 가능
    str1[0] = 'F';

    // 불가
    // str1 = nullptr;

    const char *str2 = "Fixed string";

    // 불가
    // str2[0] = 'S';

    // 가능
    str2 = nullptr;

    return 0;
}
