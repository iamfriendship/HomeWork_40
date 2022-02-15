

#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;

// 
class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {

        ReSize(_Other.Size_);

        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return ;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        if (nullptr != ArrData_)
        {
            DataType* tempArr = new DataType[_Size];
            for (size_t i = 0; i < _Size; i++)
            {
                if (i >= Size_)
                {
                    tempArr[i] = 0;
                    continue;
                }
                tempArr[i] = ArrData_[i];

            }
            Release();
            ArrData_ = tempArr;
            Size_ = _Size;
            return;
        }
        Release();
        ArrData_ = new DataType[_Size];
        Size_ = _Size;
    }


public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(10);
    std::cout << "NewArray 10 생성 " << std::endl;
    GameArray NewArray2 = GameArray(20);
    std::cout << "NewArray2 생성 " << std::endl;
    int Size = sizeof(GameArray);


    // 값 입력
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }
    std::cout << "NewArray 출력 " << std::endl;

    NewArray2 = NewArray;

    std::cout << "NewArray2 값복사 " << std::endl;

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }
    std::cout << "NewArray2 출력 " << std::endl;

    NewArray2.ReSize(20);
    std::cout << "NewArray2 리사이즈 20 " << std::endl;

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }
    std::cout << "NewArray2 출력 " << std::endl;

    NewArray2.ReSize(5);
    std::cout << "NewArray2 리사이즈 5 " << std::endl;

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }
    std::cout << "NewArray2 출력 " << std::endl;

}
