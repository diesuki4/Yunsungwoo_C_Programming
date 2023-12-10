#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int num = 100, *ptr1 = &num;
    
    // 포인터 변수 선언의 * 은
    // 변수마다 붙여주어야 한다.
    int *ptr2 = ptr1, *ptr3 = ptr2;

    return 0;
}
