#include "TextScreen.h"
#include <iostream>


TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0, 0)
	, DefaultPixel_() // ��� �����ʿ䰡 ����.
{
	CreateScreen(_Width, _Height, _DefaultValue);
}

TextScreen::~TextScreen() 
{
	for (int i = 0; i < Size_.y_; i++)
	{
		if (nullptr != PixelData_)
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}

	if (nullptr != PixelData_)
	{
		delete[] PixelData_;
		PixelData_ = nullptr;
	}
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;

	PixelData_ = new char*[Size_.y_];

	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}

void TextScreen::SettingScreen() 
{
	int RealWidth = Size_.x_ * 2;
	RealWidth += 1;

	for (int y = 0; y < Size_.y_; y++) // ���پ��׸��� �ݺ�
	{
		for (int x = 0; x < Size_.x_; x++) // �ʺ� ��ŭ �ݺ�
		{
			for (int i = 0; i < 2; i++) // ���ֱ�
			{
				PixelData_[y][(x * 2) + i] = DefaultPixel_[i];
			}
		}
		PixelData_[y][(Size_.x_ * 2)] = '\n';
		PixelData_[y][RealWidth] = 0;
	}

}

void TextScreen::PrintScreen() 
{
	system("cls"); //ȭ�������

	for (int y = 0; y < Size_.y_; y++) // ���پ� ���
	{
		// char*
		printf_s(PixelData_[y]);
	}
}


void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	if (_Pos.x_ > Size_.x_ - 1 || _Pos.y_ > Size_.y_ - 1)
	{
		assert(false);
	}
	if (_Pos.x_ < 0 || _Pos.y_ < 0)
	{
		assert(false);
	}
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue) 
{
	// �⺻�ڷ����� ����� �Լ��� ��¥ ������ ����

	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}