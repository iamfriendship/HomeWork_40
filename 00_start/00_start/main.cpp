
#include <iostream> 

#include <crtdbg.h> // 메모리 누수 체크

class Player
{
public:
    int Hp_;
    int MP_;

public:
    Player()
        :Hp_(100), MP_(100)
    {}
    ~Player()
    {}
};

int main()
{
    //leak 체크
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    int heapSize = 100;
    int* Ptr = new int[100]();
    delete[] Ptr;
}
