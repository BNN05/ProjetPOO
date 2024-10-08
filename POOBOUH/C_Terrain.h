#pragma once

#include "C_Case.h"
#include "IEventListener.h"
#include "Vector2D.h"
#include "C_EntityManager.h"

class C_Terrain : public IEventListener
{
public:
	void OnMove(Vector2D oldPosition,Vector2D newPosition) override;
	int lengthX = 15;
	int lengthY = 15; 
	int currentLevel = 1;
	C_Case*** map;
	C_EntityManager EntityManager;
	std::vector<C_Case*> GetPath(Vector2D positionStart, Vector2D positionEnd); 
	std::vector<C_Case*> FleePath(Vector2D positionStart, Vector2D playerPosition, int maxMoves);
	double Distance(const Vector2D& a, const Vector2D& b);
	void LoadNextMap();
	void LoadGameOver();
	void LoadWinner();

	void GenerateMap(const std::string& mapFilePath);
	void DrawTerrain();
	C_Terrain(int x, int y);
	void GenerateEntity();
	void ComputeEntity();

	C_Case* GetCaseByEntity(C_Entity* entity);

	C_Case* GetCase(int x, int y);
	std::vector<C_Case*> GetAdjacentCase(Vector2D pos);
	

	C_Terrain();
};

