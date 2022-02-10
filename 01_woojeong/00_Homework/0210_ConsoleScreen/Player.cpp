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


bool Player::Update() 
{
	int Value = _getch();
	

	switch (Value)
	{
	case 'a':
	case 'A':
		// 화면바깥으로 이동하면 이동이 안되게 해주세요.
		SetMove({-1, 0});
		break;
	case 'd':
	case 'D':
		SetMove({ 1, 0 });
		break;
	case 'w':
	case 'W':
		SetMove({ 0, -1 });
		break;
	case 's':
	case 'S':
		SetMove({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		return false;
		break;
	default:
		break;
	}
	

}

