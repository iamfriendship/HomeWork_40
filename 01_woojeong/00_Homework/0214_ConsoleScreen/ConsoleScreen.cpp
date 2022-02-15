// ConsoleScreen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include "Monster.h"
#include <crtdbg.h>
#include "ConsoleGlobalInst.h"

// typedef unsigned __int64 size_t;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GlobalStatic::MainScreen.SettingScreen();

    GlobalStatic::MonsterCreate(3, "■");
    // ㅁㅁㅁ
    // ㅁ★ㅁ
    // ㅁㅁㅁ
    while (true)
    {
        GlobalStatic::MainScreen.SettingScreen();
        GlobalStatic::MainPlayer.Render();

        for (size_t i = 0; i < Monster::GetAllMonsterCount(); i++)
        {
            Monster* IndexMonster = GlobalStatic::GetMonster(i);
            IndexMonster->Render();
        }
        GlobalStatic::MainScreen.PrintScreen();

        int Quit = GlobalStatic::MainPlayer.Update();

        if (Quit == -1)
        {
            break;
        }
        // NewMonster.Update();
    }

    GlobalStatic::Release;
}
