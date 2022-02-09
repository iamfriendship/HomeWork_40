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
	Width_ = _Width;
	Height_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	//               8      
	int RealWidth = Width_ * 2;
	RealWidth += 1;

	//                       17            8     + 1  = 137 ¹ÙÀÌÆ®
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
			for (int i = 0; i < 2; i++)
			{
				LineStart[(x * 2) + i] = DefaultPixel_[i];
			}
		}
		LineStart[(Width_ * 2)] = '\n';
	}

	PixelData_[(RealWidth * Height_)] = 0;

	printf_s(PixelData_);
}