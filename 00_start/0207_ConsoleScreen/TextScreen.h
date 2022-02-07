#pragma once

// 설명 :
class TextScreen
{
public:
	int Width_;
	int Height_;
	char* PixelData_;
	char DefaultPixel_[3];

	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	// 세팅된 값으로 그린다.
	void PrintScreen();

public:
	// constrcuter destructer
	TextScreen();
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;

protected:

private:

};