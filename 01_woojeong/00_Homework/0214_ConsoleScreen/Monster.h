#pragma once
#include "ConsoleObject.h"

// 이런 클래스가 있을거야.
// 존재만 알아도 상관이 없을때만 
// 일반적으로 참조만 가능하다(참조는 어차피 다 8바이트 이니까.)
// 전방 선언
class GlobalStatic;
// 설명 :
class Monster : public ConsoleObject
{
public:
	// 나의 private도 GlobalStatic 
	// 내부에서만큼은 public으로 사용이 가능하게 하겠다.
	friend GlobalStatic;

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void Death();
	void Update();
	static unsigned int GetAllMonsterCount();

	inline bool GetIsDeath() const
	{
		return IsDeath_;
	}

	void Render() override;

protected:

private:
	bool IsDeath_;

	// constrcuter destructer
	Monster();
	Monster(const char* _Text, const ConsoleVector& _Pos);
	~Monster();

	static unsigned int AllMonsterCount_;

};