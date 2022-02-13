#include "Monster.h"
#include "ConsoleGlobalInst.h"

unsigned int Monster::AllMonsterCount_ = 0;

unsigned int Monster::GetAllMonsterCount() 
{
	return AllMonsterCount_;
}

Monster::Monster() 
	: ConsoleObject(&GlobalStatic::MainScreen, "  ", {0,0})
{
	++AllMonsterCount_;
}

Monster::Monster(const char* _Text, const ConsoleVector& _Vector)
	: ConsoleObject(&GlobalStatic::MainScreen, _Text, _Vector)
{
	++AllMonsterCount_;
}

Monster::~Monster() 
{
	--AllMonsterCount_;
}


void Monster::Update()
{
}
