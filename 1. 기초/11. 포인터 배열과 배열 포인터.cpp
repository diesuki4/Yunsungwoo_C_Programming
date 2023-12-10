#include <iostream>

using namespace std;

// 함수 전달 시에 다음은 같다.
// void Func(int (*arrayPtr)[3])
void Func(int arrayPtr[][3])
{
    return;
}

int main(int argc, char* argv[])
{
    // 포인터 배열은 포인터의 배열을 저장한다.
    int* ptrArray[3] = {nullptr, nullptr, nullptr};

    int arr2d[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    // 배열 포인터는 다차원 배열에서
    // 배열 크기만큼 증감 연산을 통해
    // 접근하기 위해 사용한다.
    int (*arrayPtr)[3] = arr2d;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cout << (*(arrayPtr + i))[j] << " ";

        cout << endl;
    }

    return 0;
}
