#include <iostream>
#include <vector>

using namespace std;

template <size_t n1, size_t n2>
void print(int arr[][n2])
{
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}

template <size_t n1, size_t n2, size_t n3>
void print(int arr[][n2][n3])
{
    for (int i = 0; i < n1; ++i)
    {
        print<n2, n3>(arr[i]);

        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    // 불가능
    // vector<int> v(5) = {1, 2};
    // vector<int> v(5) {1, 2};
    vector<int> v = {1, 2};
    v.resize(5, 0);

    // {1, 2} 를 <초기화 리스트>라고 한다.
    // 배열 크기만큼 채우지 않으면,
    //
    // 나머지는 0으로 채워진다.
    int arr[5] = {1, 2};

    for (int i = 0; i < 5; ++i)
        cout << "v[" << i << "] = " << v[i] << ", arr[" << i << "] = " << arr[i] << endl;
    cout << "-------------" << endl;

    // 2차원 배열도 마찬가지다.
    int arr2d[3][3] = {
        {1},
        {2, 3},
        {4, 5, 6}
    };
    print<3, 3>(arr2d);
    cout << "-------------" << endl;

    // 첫 번째 크기만 생략이 가능하다.
    int arr2d2[][4] = {
        {1},
        {2, 3},
        {4, 5, 6}
    };
    print<3, 4>(arr2d2);
    cout << "-------------" << endl;

    // 2차원 배열도 메모리 상에서는 1차원이므로
    // 다음처럼 초기화도 가능하다.
    int arr2d3[3][3] = {1, 2, 3, 4, 5};
    print<3, 3>(arr2d3);
    cout << "-------------" << endl;

    // 첫 번째 크기만 생략이 가능하다.
    int arr3d3[][3][3] = {
        {{1}, {2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10}, {11, 12}},
        {{13, 14}, {15, 16, 17}, {18}},
        {19, 20, 21, 22, 23},
    };
    print<4, 3, 3>(arr3d3);

    return 0;
}
