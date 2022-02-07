#include "TextScreen.h"
#include <iostream>

TextScreen::TextScreen() 
{
}

TextScreen::~TextScreen() 
{
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	// 戚橿汐精 巷充 痕呪倉?
	Width_ = _Width;
	Height_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	//               3     
	int RealWidth = Width_ * 2;
	RealWidth += 1;

	// 33

	// けけけ
	// けけけ
	// けけけ

	// \n澗 1郊戚闘
	// けけけ\nけけけ\nけけけ\n0

	//                       7            3     + 1
	PixelData_ = new char[(RealWidth * Height_) + 1];
}

void TextScreen::PrintScreen() 
{
	int RealWidth = Width_ * 2;
	RealWidth += 1;

	for (int y = 0; y < Height_; y++)
	{
		char* LineStart = &PixelData_[(y * RealWidth)];

		for (int x = 0; x < Width_; x++)
		{
			//                            1         7   
			// けけけ\nけけけ\nけけけ\n0
			// |||||||-|||||||-|||||||0

			for (int i = 0; i < 2; i++)
			{
				LineStart[(x * 2) + i] = DefaultPixel_[i];
			}
		}
		LineStart[(Width_ * 2)] = '\n';
	}

	// 益撹 食奄昔走 溌昔背瑳臆遂
	PixelData_[(RealWidth * Height_)] = 0;

	printf_s(PixelData_);
}