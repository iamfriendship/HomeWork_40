#pragma once



// template<typename T>
using DataType = int;
using KeyType = int;

// template<typename KeyType, typename DataType>
struct GamePair
{
    KeyType first;
    DataType second;
};

GamePair make_gamePair(const KeyType& _Key, const DataType& _Data)
{
    // 맴버가 전부다 public인 녀석은 
    return GamePair{ _Key , _Data };
}

enum class MapNodeType
{
    Error,
    Root,
    LeftChild,
    RightChild,
};


// template<typename KeyType, typename DataType>
class GameMap
{
private:
    class MapNode
    {
    public:
        GamePair Pair_;
        MapNodeType Type;
        // 0 Error
        // 1 Root
        // 2 LeftChild
        // 3 RightChild

        MapNode* Parent_;
        MapNode* LeftChild_;
        MapNode* RightChild_;

    public:
        void FirstOrder()
        {
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
            if (nullptr != LeftChild_)
            {
                LeftChild_->FirstOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->FirstOrder();
            }
        }

        void MidOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MidOrder();
            }
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
            if (nullptr != RightChild_)
            {
                RightChild_->MidOrder();
            }
        }

        void LastOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MidOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->MidOrder();
            }
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
        }



        // 내보다 큰 부모를 찾는 함수
        MapNode* OverParent(const KeyType& _Key)
        {
            if (nullptr == Parent_)
            {
                return nullptr;
            }

            // 부모의 키가             찾으려는 키보다 작을수 있다.
            if (Parent_->Pair_.first < _Key)
            {
                return Parent_->OverParent(_Key);
            }

            return Parent_;
        }

        MapNode* NextNode()
        {
            if (nullptr != RightChild_)
            {
                return RightChild_->MinNode();
            }

            return OverParent(Pair_.first);
        }

        MapNode* MinNode()
        {
            if (nullptr == LeftChild_)
            {
                return this;
            }

            return LeftChild_->MinNode();
        }

        MapNode* MaxNode()
        {
            if (nullptr == RightChild_)
            {
                return this;
            }

            return RightChild_->MaxNode();
        }

        MapNode* Find(const KeyType& _Key)
        {
            // 내 값이 크다.

            if (Pair_.first == _Key)
            {
                return this;
            }

            if (Pair_.first > _Key)
            {
                if (nullptr == LeftChild_)
                {
                    return nullptr;
                }

                return LeftChild_->Find(_Key);
            }
            // 내 값이 더 작다.
            else if (Pair_.first < _Key)
            {
                if (nullptr == RightChild_)
                {
                    return nullptr;
                }

                return RightChild_->Find(_Key);
            }

            return nullptr;
        }

        bool Insert(const GamePair& _Pair)
        {

            // 순수하게 지금 현재 내 값이 얼마안지 
            GamePair ThisPair = Pair_;

            // 내 값이 크다.
            if (Pair_.first > _Pair.first)
            {
                if (nullptr == LeftChild_)
                {
                    LeftChild_ = new MapNode();
                    LeftChild_->Pair_ = _Pair;
                    LeftChild_->Parent_ = this;
                    LeftChild_->Type = MapNodeType::LeftChild;
                    return true;
                }

                return LeftChild_->Insert(_Pair);
            }
            // 내 값이 더 작다.
            else if (Pair_.first < _Pair.first)
            {
                if (nullptr == RightChild_)
                {
                    RightChild_ = new MapNode();
                    RightChild_->Pair_ = _Pair;
                    RightChild_->Parent_ = this;
                    RightChild_->Type = MapNodeType::RightChild;
                    return true;
                }

                return RightChild_->Insert(_Pair);
            }

            return false;
        }
        


        MapNode()
            : Parent_(nullptr)
            , LeftChild_(nullptr)
            , RightChild_(nullptr)
        {
        }
        ~MapNode()
        {
            if (nullptr != this)
            {
                delete this->LeftChild_;
                delete this->RightChild_;
                this->LeftChild_ = nullptr;
                this->RightChild_ = nullptr;
                iterator(DeleteRoot());
            }
        }

    };

public:
    class iterator
    {
    private:
        MapNode* Node_;

    public:
        GamePair* operator->()
        {
            return &(Node_->Pair_);
        }

        bool operator!=(const iterator& _Other) const
        {
            return Node_ != _Other.Node_;
        }

        bool operator==(const iterator& _Other) const
        {
            return Node_ == _Other.Node_;
        }

        iterator& operator++()
        {
            Node_ = Node_->NextNode();
            return *this;
        }

    public:
        iterator(MapNode* _Node)
            : Node_(_Node)
        {

        }

        iterator()
            : Node_(nullptr)
        {

        }
    };

public:
    // 시발점이 되는 노드
    MapNode* RootNode_;



    bool insert(const GamePair& _Pair)
    {
        // 체크할수밖에 없습니다.
        if (nullptr == RootNode_)
        {
            RootNode_ = new MapNode();
            RootNode_->Type = MapNodeType::Root;
            RootNode_->Pair_ = _Pair;
            return true;
        }

        return RootNode_->Insert(_Pair);
    }

    iterator Find(const KeyType& _Key)
    {
        return GameMap::iterator(RootNode_->Find(_Key));
    }

    iterator begin()
    {
        return GameMap::iterator(RootNode_->MinNode());
    }

    iterator end()
    {
        return GameMap::iterator(nullptr);
    }

    void FirstOrder() {
        RootNode_->FirstOrder();
    }

    void MidOrder() {
        RootNode_->MidOrder();
    }

    void LastOrder() {
        RootNode_->LastOrder();
    }

    void DeleteRoot()
    {
        if ((nullptr != RootNode_))
        {
            delete RootNode_;
            RootNode_ = nullptr;
        }

    }




public:
    GameMap()
        : RootNode_(nullptr)
    {

    }

    ~GameMap()
    {
        if (nullptr != RootNode_)
        {
            delete RootNode_;
            RootNode_ = nullptr;
        }
    }
};

