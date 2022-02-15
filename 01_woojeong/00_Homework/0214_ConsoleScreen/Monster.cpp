#include "Monster.h"
#include "ConsoleGlobalInst.h"

unsigned int Monster::AllMonsterCount_ = 0;

unsigned int Monster::GetAllMonsterCount() 
{
	return AllMonsterCount_;
}

Monster::Monster() 
	: ConsoleObject(&GlobalStatic::MainScreen, "  ", {0,0}),
	IsDeath_(false)
{
	++AllMonsterCount_;
}

Monster::Monster(const char* _Text, const ConsoleVector& _Vector)
	: ConsoleObject(&GlobalStatic::MainScreen, _Text, _Vector),
	IsDeath_(false)
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

void Monster::Death() 
{
	IsDeath_ = true;
}

void Monster::Render()
{
	if (true == GetIsDeath())
	{
		return;
	}

	// �θ��� �Լ��� ȣ���Ұž�.
	ConsoleObject::Render();
}