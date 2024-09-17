#pragma once

#include "C_Terrain.h"
#include "Vector2D.h"

class C_Game
{
public:
	C_Game();
	~C_Game();
	void Init();
	void Draw();
	void StartGame(); //Init
	void ResetGame();

	static C_Game Instance;

	C_Terrain Terrain;

};


