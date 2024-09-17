#include <iostream>
#include "C_Game.h"
#include "Windows.h"

int main()
{

	SetConsoleOutputCP(CP_UTF8);
	C_Game game{};
	game.StartGame();
}
