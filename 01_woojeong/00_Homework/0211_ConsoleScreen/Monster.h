#pragma once
#include "ConsoleObject.h"

// �̷� Ŭ������ �����ž�.
// ���縸 �˾Ƶ� ����� �������� 
// �Ϲ������� ������ �����ϴ�(������ ������ �� 8����Ʈ �̴ϱ�.)
// ���� ����
class GlobalStatic;
// ���� :
class Monster : public ConsoleObject
{
public:
	// ���� private�� GlobalStatic 
	// ���ο�����ŭ�� public���� ����� �����ϰ� �ϰڴ�.
	friend GlobalStatic;


	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;


	void Update();
	static unsigned int GetAllMonsterCount();

protected:

private:
	// constrcuter destructer
	Monster();
	Monster(const char* _Text, const ConsoleVector& _Pos);
	~Monster();

	static unsigned int AllMonsterCount_;
};