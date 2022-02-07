#pragma once

// 설명 :
class TextScreen
{
public:
	// 고정되어서 절대로 바꿀수 없다.
	// 맴버 정적 배열
	// 그래도 정적배열이기 때문에 고칠수가 없습니다.
	// 이걸로 해결이 된다면

	int Width_;
	int Height_;
	char* PixelData_;
	// 이녀석은 값 그자체를 들고 있을 것이므로 포인터 이면 안됩니다.
	char DefaultPixel_[3];

	// 화면의 너비와 높이 그리고 화면을 채울 _DefaultValue를 세팅한다.
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

