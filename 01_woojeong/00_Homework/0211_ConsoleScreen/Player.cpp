#include "Player.h"
#include <conio.h>
#include "ConsoleGlobalInst.h"

Player::Player(TextScreen* _Screen, const char* _Text)
	: ConsoleObject(_Screen, _Text, _Screen->GetSize().GetHalfVector())
{
}

Player::~Player() 
{
}


int Player::Update() 
{
	// GlobalValue::AllMonsters

	// AllMonsters[2];

	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();
	ConsoleVector PlayerPos = GlobalStatic::MainPlayer.GetPos();
	ConsoleVector ScreenSize = GlobalStatic::MainScreen.GetSize();

	switch (Value)
	{
	case 'a':
	case 'A':
		if (PlayerPos.x_ > 0)
		{
			SetMove({ -1, 0 });
		}
		break;
		// 화면바깥으로 이동하면 이동이 안되게 해주세요.
	case 'd':
	case 'D':
		if (PlayerPos.x_ < (ScreenSize.x_ - 1))
		{
			SetMove({ 1, 0 });
		}
		break;
	case 'w':
	case 'W':
		if (PlayerPos.y_ > 0)
		{
			SetMove({ 0, -1 });
		}
		break;
	case 's':
	case 'S':
		if (PlayerPos.y_ < (ScreenSize.y_ - 1))
		{
			SetMove({ 0, 1 });
		}
		break;
	case 'q':
	case 'Q':
		// 무슨일인가가 벌어져서
		// 게임이 종료된다.
		return -1;
	default:
		break;
	}
	
	return 1;
}

