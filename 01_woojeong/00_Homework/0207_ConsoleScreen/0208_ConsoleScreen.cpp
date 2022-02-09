// ConsoleScreen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "TextScreen.h"

int main()
{
    // 스택에 n바이트가 할당되었을것이다
    TextScreen NewScreen;

    NewScreen.CreateScreen(8, 8, "□");

    NewScreen.PrintScreen();
}
