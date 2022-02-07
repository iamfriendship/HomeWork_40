#pragma once

// ���� :
class TextScreen
{
public:
	// �����Ǿ ����� �ٲܼ� ����.
	// �ɹ� ���� �迭
	// �׷��� �����迭�̱� ������ ��ĥ���� �����ϴ�.
	// �̰ɷ� �ذ��� �ȴٸ�

	int Width_;
	int Height_;
	char* PixelData_;
	// �̳༮�� �� ����ü�� ��� ���� ���̹Ƿ� ������ �̸� �ȵ˴ϴ�.
	char DefaultPixel_[3];

	// ȭ���� �ʺ�� ���� �׸��� ȭ���� ä�� _DefaultValue�� �����Ѵ�.
	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	// ���õ� ������ �׸���.
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

