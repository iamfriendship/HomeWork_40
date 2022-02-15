#pragma once
#include "TextScreen.h"
#include "Monster.h"
#include "Player.h"
//
//extern TextScreen MainScreen;
//extern Monster* AllMonsters;
//extern Player MainPlayer;

class GlobalStatic 
{
	// 클래스 정적 변수를 선언할수가 있습니다.
public:
	// 클래스에 속한 전역변수가 됩니다.
	static TextScreen MainScreen;
	static Player MainPlayer;

	static void MonsterCreate(unsigned int _Count, const char* _Text);
	static void Release();

	// 몬스터는 절대로 중간에 삭제가 되어서는 안된다.
	// 지우면 안됩니다.
	static Monster* GetAllMonsters();

	static Monster* GetMonster(unsigned int _Index);

	static Monster* GetMonster(const ConsoleVector& _Pos);

private:
	static Monster* AllMonsters;
};

// 굳이 이렇게 할필요가 없습니다.
// extern GlobalValue Inst;

//
//// 설명 :
//class ConsoleGlobalInst
//{
//public:
//	// constrcuter destructer
//	ConsoleGlobalInst();
//	~ConsoleGlobalInst();
//
//	// delete Function
//	ConsoleGlobalInst(const ConsoleGlobalInst& _Other) = delete;
//	ConsoleGlobalInst(ConsoleGlobalInst&& _Other) noexcept = delete;
//	ConsoleGlobalInst& operator=(const ConsoleGlobalInst& _Other) = delete;
//	ConsoleGlobalInst& operator=(ConsoleGlobalInst&& _Other) noexcept = delete;
//
//protected:
//
//private:
//
//};

