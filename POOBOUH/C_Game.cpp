#include "C_Game.h"
#include "Windows.h"


C_Game::C_Game() : Terrain(15,15) {
}

C_Game::~C_Game()
{
}

void C_Game::Init()
{
}

void C_Game::Draw()
{
}

void C_Game::StartGame()
{
	C_Game::Terrain.GenerateMap();
	C_Game::Terrain.DrawTerrain();   
	getchar();
	system("cls");
	C_Game::Terrain.DrawTerrain();
}

void C_Game::ResetGame()
{
}
