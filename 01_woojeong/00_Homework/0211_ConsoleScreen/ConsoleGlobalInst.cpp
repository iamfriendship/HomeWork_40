#include "ConsoleGlobalInst.h"
#include <iostream>

TextScreen GlobalStatic::MainScreen(10, 10, "¤±");
Monster* GlobalStatic::AllMonsters = nullptr;
Player GlobalStatic::MainPlayer(&MainScreen, "¡Ú");

void GlobalStatic::Release()
{
	if (nullptr != AllMonsters)
	{
		delete[] AllMonsters;
		AllMonsters = nullptr;
	}
}

void GlobalStatic::MonsterCreate(unsigned int _Count, const char* _Text)
{
	AllMonsters = new Monster[_Count];


	for (int i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		Monster* IndexMonster = GlobalStatic::GetMonster(i);
		IndexMonster->SetRenderChar(_Text);
		IndexMonster->SetPos({ i, 0 });
	}
}

Monster* GlobalStatic::GetAllMonsters() 
{
	return AllMonsters;
}

Monster* GlobalStatic::GetMonster(unsigned int _Index)
{
	if (_Index >= Monster::GetAllMonsterCount())
	{
		return nullptr;
	}

	return &AllMonsters[_Index];
}