#include <iostream>

using namespace std;

/*
 * C의 절차 지향
 *
 * 어떤 사건을 시간 순서로 배열하는 데 효과적이다.
 * 아침에 일어나서 -> 씻고 -> 밥을 먹고 -> 옷을 입고 -> 출근한다.
 *
 * C++ 보다 속도가 빠르다.
 * 큰 문제를 <함수> 단위로 쪼개어 해결한다.
 */

void Wake()     { cout << "1. 일어난다." << endl; }
void Wash()     { cout << "2. 씼는다." << endl; }
void Eat()      { cout << "3. 밥을 먹는다." << endl; }
void Wear()     { cout << "4. 옷을 입는다." << endl; }
void GoToWork() { cout << "5. 출근한다." << endl << endl; }

void C_Procedural()
{
    cout << "[절차 지향]" << endl;

    Wake();

    Wash();

    Eat();

    Wear();

    GoToWork();
}

/*
 * C++의 객체 지향
 *
 * 어떤 사건을 객체 간의 상호작용으로 나타내는 데 효과적이다.
 * (나)가 (상인)에게 (5000원)을 주고 (사과 5개)를 샀다.
 *
 * 다형적 클래스(가상 함수가 1개 이상 포함된)는 VFTable을
 * 참조해야 하므로, C보다는 속도가 느리다.
 * 큰 문제를 <객체> 단위로 쪼개어 해결한다.
 */

class Merchant
{
    int money;
    int nApple;
    const int applePrice;

public:
    Merchant(int nApple) : money(0), nApple(nApple), applePrice(1000) { }

    int Sell(int money)
    {
        int nRequested = money / applePrice;

        if (nRequested <= nApple)
        {
            cout << "(상인)에게 (사과 " << nRequested << "개)를 샀다." << endl;

            nApple -= nRequested;
            this->money += money;

            return nRequested;
        }

        return 0;
    }
};

class Me
{
    int money;
    int nApple;

public:
    Me(int money) : money(money), nApple(0) { }

    void Buy(Merchant& ref, int money)
    {
        if (money <= this->money)
        {
            cout << "(나)가 (" << money << "원)을 주고 ";

            nApple += ref.Sell(money);
            this->money -= money;
        }
    }
};

void CPP_Object_Oriented()
{
    cout << "[객체 지향]" << endl;

    Me me(10000);
    Merchant merchant(10);

    me.Buy(merchant, 5000);
}

int main(int argc, char* argv[])
{
    C_Procedural();

    CPP_Object_Oriented();

    return 0;
}
