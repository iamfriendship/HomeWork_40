
#include <iostream>
#include <map>
#include "GameMap.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   /* {
       std::map<int, int> StdMap;
       // 같은 값은 무시되므로 값형으로 넣어줄때는 크게 신경쓸 필요가 없다.
       StdMap.insert(std::make_pair(10, 10));
       StdMap.insert(std::make_pair(10, 1));
       StdMap.insert(std::make_pair(10, 2));
   
       StdMap.insert(std::make_pair(30, 2));
       StdMap.insert(std::make_pair(5, 1));
       StdMap.insert(std::make_pair(7, 1));
       StdMap.insert(std::make_pair(1, 1));
   
       std::map<int, int>::iterator beginIter = StdMap.begin();
       std::map<int, int>::iterator endIter = StdMap.end();
   
       for (; beginIter != endIter; ++beginIter)
       {
           std::cout << beginIter->first << std::endl;
       }
   }*/

    {
        GameMap GMap;

        GMap.insert(make_gamePair(10, 10));
        GMap.insert(make_gamePair(10, 1));
        GMap.insert(make_gamePair(10, 2));
        GMap.insert(make_gamePair(5, 1));
        GMap.insert(make_gamePair(7, 1));
        GMap.insert(make_gamePair(1, 1));
        GMap.insert(make_gamePair(20, 1));
        GMap.insert(make_gamePair(25, 1));
        GMap.insert(make_gamePair(17, 1));

        std::cout << std::endl;
        std::cout << "전위 순회" << std::endl;
        GMap.FirstOrder(); // 전위순회
        std::cout << std::endl;
        std::cout << "중위 순회" << std::endl;
        GMap.MidOrder(); // 중위순회
        std::cout << std::endl;
        std::cout << "후위 순회" << std::endl;
        GMap.LastOrder(); // 후위순회



        std::cout << std::endl;
        std::cout << "이터레이터 순회" << std::endl;
        GameMap::iterator beginIter = GMap.begin();
        GameMap::iterator endIter = GMap.end();

        for (; beginIter != endIter; ++beginIter)
        {
            std::cout << beginIter->first << std::endl;
        }

    }
}
