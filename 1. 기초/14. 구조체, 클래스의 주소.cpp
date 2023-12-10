#include <iostream>

using namespace std;

struct StPoint { int x; int y; };
class  ClPoint { public: int x; int y; };

int main(int argc, char* argv[])
{
    StPoint st {1, 2};
    ClPoint cl {3, 4};

    // 구조체, 클래스의 주소는
    // 첫 번째 멤버 변수의 주소와 같다.
    cout << "&st = " << &st << ", &st.x = " << &st.x << endl;
    cout << "&cl = " << &cl << ", &cl.x = " << &cl.x << endl << endl;

    int* ptr = &st.x + 1;
    cout << "st.y = " << *ptr << endl;

    ptr = &cl.x + 1;
    cout << "cl.y = " << *ptr << endl;

    return 0;
}
