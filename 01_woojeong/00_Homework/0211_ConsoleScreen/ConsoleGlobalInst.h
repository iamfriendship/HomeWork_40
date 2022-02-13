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
	// Ŭ���� ���� ������ �����Ҽ��� �ֽ��ϴ�.
public:
	// Ŭ������ ���� ���������� �˴ϴ�.
	static TextScreen MainScreen;
	static Player MainPlayer;

	static void MonsterCreate(unsigned int _Count, const char* _Text);
	static void Release();

	// ���ʹ� ����� �߰��� ������ �Ǿ�� �ȵȴ�.
	// ����� �ȵ˴ϴ�.
	static Monster* GetAllMonsters();

	static Monster* GetMonster(unsigned int _Index);

private:
	static Monster* AllMonsters;
};

// ���� �̷��� ���ʿ䰡 �����ϴ�.
// extern GlobalValue Inst;

//
//// ���� :
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

