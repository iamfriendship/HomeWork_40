#pragma once
#include <list>
#include "GameBlock.h"
// 설명 :

class Body;
//전방선언바디 클래스 전방선언

class Head : public GameBlock
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

protected:
	void Update() override;

	void OverLap(ConsoleObject* _Other);

private:
	std::list<Body*> AllBody;
};

