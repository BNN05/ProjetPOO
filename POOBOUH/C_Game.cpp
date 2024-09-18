#include "C_Game.h"
#include "Windows.h"

C_Game C_Game::Instance;

C_Game::C_Game() : Terrain(26,26) , Player(nullptr)
{
	C_Game::Instance = *this;
}

C_Game::~C_Game()
{
}

void C_Game::Init()
{
}

void C_Game::Draw()
{
	system("cls");
	C_Game::Terrain.DrawTerrain();
}

void C_Game::StartGame()
{
	C_Game::Terrain.GenerateMap(); 
	Draw();
	while (true)
	{
		C_Game::Terrain.EntityManager.ComputeEntities();
	}
	/*getchar();
	system("cls");
	C_Game::Terrain.DrawTerrain();*/
}

void C_Game::ResetGame()
{
}
