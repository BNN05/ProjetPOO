#pragma once

#include "C_Case.h"

class C_Terrain
{
public:
	int lengthX = 15;
	int lengthY = 15;
	C_Case map[15][15];

	void GenerateMap();
	void GenerateEntity();
};

