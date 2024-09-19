#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "C_Game.h"
#include "Windows.h"

C_Game* C_Game::Instance;

C_Game::C_Game() : Terrain(26,26) , Player(nullptr)
{
	C_Game::Instance = this;
}

C_Game::~C_Game()
{
}

void C_Game::Init()
{
}

void C_Game::Draw()
{

    C_Game::ClearConsole();
	
	C_Game::Screen.DrawEnemyScreen();
	C_Game::Terrain.DrawTerrain();
	C_Game::Screen.DrawPlayerScreen();
}

void C_Game::StartGame()
{
    
	C_Game::Terrain.GenerateMap("MapFiles/level1.csv");
	Draw();
	while (true)
	{
		C_Game::Terrain.EntityManager.ComputeEntities();
	}
}

void C_Game::ResetGame()
{
}

void C_Game::ClearConsole()
{
    //system("cls"); //OLD
    
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

 
    std::cout.flush();

    
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    
    SetConsoleCursorPosition(hOut, topLeft);
}

