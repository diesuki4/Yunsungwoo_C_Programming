#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int arr2d[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    // 세 값은 같다.
    // 
    // 역참조 한 값이 같을 지라도
    // 포인터의 깊이(자료형)가 다르다.

    // 2차원 배열의 시작 주소
    cout << "int *[][3] arr2d = " << arr2d << endl;
    // 2차원 배열의 첫 번째 배열의 시작 주소
    cout << "int *[3] arr2d[0] = " << arr2d[0] << endl;
    // 2차원 배열의 첫 번째 배열의 시작 주소
    cout << "int *[3] *arr2d = " << *arr2d << endl;

    for (int i = 0; i < 4; ++i)
    {
        // 다차원 배열 주소에서의 증감 연산은
        // (n-1)차원 배열의 크기만큼 진행된다.
        for (int j = 0; j < 3; ++j)
            cout << (*(arr2d + i))[j] << " ";

        cout << endl;
    }

    return 0;
}
