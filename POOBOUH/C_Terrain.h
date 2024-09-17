#pragma once

#include "C_Case.h"

class C_Terrain
{
public:
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

