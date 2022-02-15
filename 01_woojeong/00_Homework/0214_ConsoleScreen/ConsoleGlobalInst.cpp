#include "ConsoleGlobalInst.h"
#include "ConsoleRandom.h"
#include <time.h>

TextScreen GlobalStatic::MainScreen(10, 10, "¤±");
Monster* GlobalStatic::AllMonsters = nullptr;
Player GlobalStatic::MainPlayer(&MainScreen, "¡Ú");

Monster* GlobalStatic::GetMonster(const ConsoleVector& _Pos)
{
	for (size_t i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		if (AllMonsters[i].GetPos() == _Pos
			&& false == AllMonsters[i].GetIsDeath())
		{
			return &AllMonsters[i];
		}
	}

	return nullptr;
}

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

	ConsoleRandom Random = ConsoleRandom(time(nullptr));
	
	//·£´ý

	for (int i = 0; i < Monster::GetAllMonsterCount(); i++)
	{
		Monster* IndexMonster = GlobalStatic::GetMonster(i);
		IndexMonster->SetRenderChar(_Text);
		IndexMonster->SetPos(
			{ (int)Random.Next(MainScreen.GetSize().x_), 
			(int)Random.Next(MainScreen.GetSize().y_) });
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