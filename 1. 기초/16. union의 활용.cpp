#include <iostream>

using namespace std;

// 사실 공용체도
// 구조체나 클래스처럼 사용할 수 있다.
//
// 기본적으로 public 이므로
// 공간을 공유한다는 점을 제외하면
//
// 구조체와 같다.
template <typename T>
union UnionWrapper
{
    // 공간을 공유하므로
    // T 타입의 메모리를
    T data;
    // 바이트 단위로 확인할 수 있다.
    char bytes[sizeof(T)];

    UnionWrapper(T data) : data(data) { }

    void ShowBytes()
    {
        for (int i = 0; i < sizeof(T); ++i)
            cout << hex << static_cast<int>(bytes[i]) << " ";

        cout << endl;
    }

    // 실제 데이터를 반환한다.
    T& Get() { return data; }
};

class AAA
{
    int num;
    char c;
    long l;
    bool b;

public:
    AAA(int num, char c, long l, bool b) : num(num), c(c), l(l), b(b) { }

    void Show() { cout << num << " " << c << " " << l << " " << boolalpha << b << endl; }
};

// 공용체는 하나의 값 내에서도
// 공간에 따른 의미를 가질 때 유용하다.
union Packed
{
    // 공용체 내에 구조체나 클래스를 정의할 수도 있다.
    struct user_info { short user_id; short level; };
    
    user_info info;
    int rawData;
};

int main(int argc, char* argv[])
{
    UnionWrapper<AAA> aaa(AAA(5, 'A', 0x0A0B0C0D, true));

    aaa.ShowBytes();
    aaa.Get().Show();

    int user_id = 213, level = 56;
    Packed pack;

    pack.rawData = (level << 16) | user_id;

    cout << dec << "user_id = " << pack.info.user_id << ", level = " << pack.info.level << endl;

    return 0;
}
