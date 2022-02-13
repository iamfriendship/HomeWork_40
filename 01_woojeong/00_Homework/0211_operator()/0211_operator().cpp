
#include <iostream>
using namespace std;



int a = 2;
int b = 3;

int Sum()
{
    return a + b;

}

class Firstclass
{
private:
    int a_ = a;
    int b_ = b;

public:

    int GetIntA()
    {
        return a_;
    }

    int GetIntB()
    {
        return b_;
    }


    int operator ()()
    {
        return Sum();
    }
    // ..?
};

int main()
{
    Firstclass TestClass1;


    cout << "a 값은 " << TestClass1.GetIntA() << endl;
    cout << "b 값은 " << TestClass1.GetIntB() << endl;
    cout << "operator()()값은 " << TestClass1() << endl;
}
