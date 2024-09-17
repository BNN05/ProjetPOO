#pragma once

#include "C_Case.h"
#include "IEventListener.h"
#include "Vector2D.h"

class C_Terrain :public IEventListener
{
public:
	void OnMove(Vector2D newPosition) override;
	int lengthX = 15;
	int lengthY = 15; 
	C_Case*** map;

	void GenerateMap();
	void DrawTerrain();
	C_Terrain(int x, int y);
	void GenerateEntity();

	C_Case GetCase();


	C_Terrain();
};

