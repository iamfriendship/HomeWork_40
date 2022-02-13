#include "ConsoleObject.h"

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
	)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	//if (nullptr == _Screen)
	//{
	//	assert(false);
	//}

	SetRenderChar(_Text);
}

ConsoleObject::~ConsoleObject() 
{
}

void ConsoleObject::Render() 
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}


void ConsoleObject::SetRenderChar(const char* _Text)
{

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}