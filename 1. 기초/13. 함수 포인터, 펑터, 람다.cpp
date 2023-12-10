#include <iostream>
#include <functional>

using namespace std;

/*
 * 함수 포인터
 */
bool AscendingCompare(int A, int B) { return A > B; }

void BubbleSort(int arr[], const bool (*fptr)(int, int))
{
    const size_t size = 5;

    for (int i = 0; i < (size - 1); ++i)
        for (int j = 0; j < (size - 1) - i; ++j)
            if (fptr(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

/*
 * 펑터
 */
class SortRule abstract
{
public:
    virtual bool operator() (int A, int B) const = 0;
    virtual ~SortRule() { }
};

class AscendingRule : public SortRule
{
public:
    virtual bool operator() (int A, int B) const override { return A > B; }
};

void BubbleSort(int arr[], const SortRule& functor)
{
    const size_t size = 5;

    for (int i = 0; i < (size - 1); ++i)
        for (int j = 0; j < (size - 1) - i; ++j)
            if (functor(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

/*
 * 람다
 */
void BubbleSort(int arr[], const function<bool(int, int)> lambda)
{
    const size_t size = 5;

    for (int i = 0; i < (size - 1); ++i)
        for (int j = 0; j < (size - 1) - i; ++j)
            if (lambda(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

void Fill(int arr[]) { arr[0] = 4, arr[1] = 2, arr[2] = 5, arr[3] = 1, arr[4] = 3; }
void Show(int arr[]) { for (int i = 0; i < 5; ++i) cout << arr[i] << " "; cout << endl; }

int main(int argc, char* argv[])
{
    int arr[5];

    /*
     * 함수 포인터
     *
     * 매번 필요한 함수를 정의해야 하는 단점이 있다.
     */
    Fill(arr);
    BubbleSort(arr, AscendingCompare);
    Show(arr);

    /*
     * 펑터
     *
     * 펑터를 정의해야 하므로 번거롭다.
     * 
     * 클래스 내부에 정의된 멤버 함수는 inline 처리되기 때문에
     * 성능상 이점이 있다.
     * 
     * 추상 클래스 상속을 이용해
     * 여러 다른 동작들을 쉽게 전달할 수 있다.
     */
    Fill(arr);
    BubbleSort(arr, AscendingRule());
    Show(arr);

    /*
     * 람다
     * 
     * 함수나 펑터를 정의하지 않고
     * 바로 함수를 만들어 전달할 수 있다.
     * 
     * 스택에 이름 없이 저장되는 임시 오브젝트이며
     * 생성자와 소멸자도 갖는다.
     */
    Fill(arr);
    BubbleSort(arr, [](int A, int B) { return A > B; });
    Show(arr);

    return 0;
}
