#pragma once

#include "C_Case.h"
#include "IEventListener.h"
#include "Vector2D.h"
#include "C_EntityManager.h"

class C_Terrain :public IEventListener
{
public:
	void OnMove(Vector2D oldPosition,Vector2D newPosition) override;
	int lengthX = 15;
	int lengthY = 15; 
	C_Case*** map;
	C_EntityManager EntityManager;
	std::vector<C_Case*> GetPath(Vector2D positionStart, Vector2D positionEnd);
	void GenerateMap();
	void DrawTerrain();
	C_Terrain(int x, int y);
	void GenerateEntity();

	C_Case* GetCase(int x, int y);
	

	C_Terrain();
};

