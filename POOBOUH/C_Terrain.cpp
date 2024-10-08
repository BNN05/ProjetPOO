﻿#include "C_Terrain.h"
#include <iostream>
#include "Windows.h"
#include <string>
#include "C_TerrainLoader.h"
#include "C_Golem.h"
#include "C_Spectre.h"
#include "C_Reaper.h"
#include "C_Player.h"
#include "C_Game.h"
#include <queue>
#include <vector>
#include <utility> // Pour std::pair
#include <algorithm> 
#include <map>
#include "C_Chest.h"
#include <filesystem>

void C_Terrain::OnMove(Vector2D oldPosition,Vector2D newPosition) {
	if (map[(int)oldPosition.x][(int)oldPosition.y]->entity == nullptr)
		return;
	if (map[(int)newPosition.x][(int)newPosition.y]->entity != nullptr)
		return;


	map[(int)newPosition.x][(int)newPosition.y]->AddEntity(map[(int)oldPosition.x][(int)oldPosition.y]->entity);
	map[(int)oldPosition.x][(int)oldPosition.y]->entity = nullptr;

}
std::vector<C_Case*> C_Terrain::GetPath(Vector2D positionStart, Vector2D positionEnd)
{
	std::vector<C_Case*> path;
	std::queue<Vector2D> queue;

	std::vector<std::vector<bool>> visited(lengthX, std::vector<bool>(lengthY, false));

	std::vector<Vector2D> directions = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0} 
	};

	queue.push(positionStart);
	visited[positionStart.x][positionStart.y] = true;

	std::map<Vector2D, Vector2D> cameFrom;

	while (!queue.empty()) {
		Vector2D current = queue.front();
		queue.pop();

		if (current == positionEnd) {
			break; 
		}

		for (const auto& direction : directions) {
			Vector2D neighbor = current + direction;

			if (neighbor.x < 0 || neighbor.x >= lengthX ||
				neighbor.y < 0 || neighbor.y >= lengthY) {
				continue;
			}

			C_Case* caseNeighbor = GetCase(neighbor.x, neighbor.y);
			if (caseNeighbor->caseType == E_CaseType::Wall || visited[neighbor.x][neighbor.y]) {
				continue; 
			}

			visited[neighbor.x][neighbor.y] = true;
			queue.push(neighbor);
			cameFrom[neighbor] = current; 
		}
	}

	Vector2D current = positionEnd;
	while (current != positionStart) {
		path.push_back(GetCase(current.x, current.y));
		if (cameFrom.find(current) == cameFrom.end()) {
			break; 
		}
		current = cameFrom[current];
	}

	std::reverse(path.begin(), path.end());
	return path;
}

std::vector<C_Case*> C_Terrain::FleePath(Vector2D positionStart, Vector2D playerPosition, int maxMoves)
{
	std::vector<C_Case*> path;
	std::queue<std::pair<Vector2D, int>> queue;

	std::vector<std::vector<bool>> visited(lengthX, std::vector<bool>(lengthY, false));

	std::vector<Vector2D> directions = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0}
	};

	queue.push({ positionStart, 0 });  
	visited[positionStart.x][positionStart.y] = true;

	std::map<Vector2D, Vector2D> cameFrom;
	Vector2D furthestPosition = positionStart;
	double maxDistance = Distance(positionStart, playerPosition); 

	while (!queue.empty()) {
		std::pair<Vector2D, int> front = queue.front();
		Vector2D current = front.first;
		int moves = front.second;
		queue.pop();

		if (moves >= maxMoves) {
			continue;
		}

		for (const auto& direction : directions) {
			Vector2D neighbor = current + direction;

			if (neighbor.x < 0 || neighbor.x >= lengthX ||
				neighbor.y < 0 || neighbor.y >= lengthY) {
				continue;
			}

			C_Case* caseNeighbor = GetCase(neighbor.x, neighbor.y);

			if (caseNeighbor->caseType == E_CaseType::Wall || visited[neighbor.x][neighbor.y]) {
				continue;
			}

			visited[neighbor.x][neighbor.y] = true;
			queue.push({ neighbor, moves + 1 }); 
			cameFrom[neighbor] = current;

			double distanceToPlayer = Distance(neighbor, playerPosition);
			if (distanceToPlayer > maxDistance) {
				maxDistance = distanceToPlayer;
				furthestPosition = neighbor;
			}
		}
	}

	Vector2D current = furthestPosition;
	while (current != positionStart) {
		path.push_back(GetCase(current.x, current.y));
		if (cameFrom.find(current) == cameFrom.end()) {
			break;
		}
		current = cameFrom[current];
	}

	std::reverse(path.begin(), path.end());
	return path;
}

double C_Terrain::Distance(const Vector2D& a, const Vector2D& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void C_Terrain::LoadNextMap()
{
 	if (currentLevel < 4)
	{
		currentLevel++;
		EntityManager.shouldStopProcessEntity = true;
		EntityManager.RemoveAllEntity();
 		GenerateMap("MapFiles/level" + std::to_string(currentLevel) + ".csv");
	}
	else {
		LoadWinner();
	}
		
}

void C_Terrain::LoadGameOver()
{
	EntityManager.shouldStopProcessEntity = true;
	C_Game::Instance->isOver = true;
	EntityManager.RemoveAllEntity();
	GenerateMap("MapFiles/GameOver.csv");
	C_Game::Instance->Draw();
}

void C_Terrain::LoadWinner()
{
	EntityManager.shouldStopProcessEntity = true;
	C_Game::Instance->isOver = true;
	EntityManager.RemoveAllEntity();
	GenerateMap("MapFiles/Win.csv");
	C_Game::Instance->Draw();
}





void C_Terrain::GenerateMap(const std::string& mapFilePath)
{
	C_TerrainLoader terrainLoader;
	auto v = terrainLoader.LoadMap(mapFilePath);
	
	for (int i = 0; i < C_Terrain::lengthX; i++) {
		for (int j = 0; j < C_Terrain::lengthY; j++) {
			C_Case* tile = new C_Case();
			if (v[i][j] != u8"🟫") { //Carré marron
				tile->Init(u8"ㅤ", Vector2D(i, j)); //Carré invisible
				tile->caseType = E_CaseType::Empty;
				if (v[i][j] != u8"ㅤ") {//Carré invisible
					if ((v[i][j] == "G"))
					{
						C_Golem* golem = new C_Golem();
						golem->Init();
						tile->AddEntity(golem);
						EntityManager.AddEntity(golem);
					
					}					
					else if ((v[i][j] == "F"))
					{
						C_Reaper* reaper = new C_Reaper();
						reaper->Init();
						tile->AddEntity(reaper);
						EntityManager.AddEntity(reaper);

					}
					else if ((v[i][j] == "S"))
					{
						C_Spectre* spectre = new C_Spectre();
						spectre->Init();
						tile->AddEntity(spectre);
						EntityManager.AddEntity(spectre);
					}
					else if ((v[i][j] == "C"))
					{
						C_Chest* chest = new C_Chest();
						chest->Init();
						tile->AddEntity(chest);
						EntityManager.AddEntity(chest);
					}
					else if ((v[i][j] == "@"))
					{
						C_Player* player = new C_Player();
						player->Init();
						tile->AddEntity(player);
						EntityManager.AddPlayer(player);
						C_Game::Instance->Player = player;
					}
				}  
			}
			else {
				tile->Init(v[i][j], Vector2D(i, j));

				tile->caseType = E_CaseType::Wall;
			}
			this->map[i][j] = tile;

		}
	}
	auto t = C_Terrain::GetPath(this->map[1][1]->position, this->map[1][8]->position);
	
}

void C_Terrain::DrawTerrain()
{

	//system("cls");
	for (int i = 0; i < C_Terrain::lengthX; i++) {
		for (int j = 0; j < C_Terrain::lengthY; j++) {
			if (C_Terrain::map[i][j]->entity != nullptr)
				std::cout << C_Terrain::map[i][j]->entity->GetSprite();
			else
				std::cout << C_Terrain::map[i][j]->sprite;
		}
		std::cout << "\n";
	}
}

C_Terrain::C_Terrain() : lengthX(0), lengthY(0), map(nullptr),EntityManager() 
{
	
}

C_Terrain::C_Terrain(int x, int y) : lengthX(x), lengthY(y) {
    // Allocation dynamique du tableau map
    map = new C_Case * *[lengthX];
    for (int i = 0; i < lengthX; ++i) {
        map[i] = new C_Case * [lengthY];
        for (int j = 0; j < lengthY; ++j) {
            map[i][j] = nullptr; // Initialiser les pointeurs à nullptr
        }
    }
}

void C_Terrain::ComputeEntity()
{
	if(!C_Game::Instance->isOver)
		EntityManager.CheckForEntityAlive();
}

C_Case* C_Terrain::GetCaseByEntity(C_Entity* entity)
{
	for (int i = 0; i < C_Terrain::lengthX; i++) {
		for (int j = 0; j < C_Terrain::lengthY; j++) {
			if (C_Terrain::map[i][j]->entity == entity)
				return C_Terrain::map[i][j];
		}
	}
}

C_Case* C_Terrain::GetCase(int x, int y)
{
	if (x >= 0 && x < lengthX && y >= 0 && y < lengthY)
	{
		return map[x][y]; // Retourne la case 
	}
	return nullptr; 
}


std::vector<C_Case*> C_Terrain::GetAdjacentCase(Vector2D pos)
{
	vector<Vector2D> adjacentPositions{};
	adjacentPositions.push_back(Vector2D(pos.x, pos.y - 1)); // Haut
	adjacentPositions.push_back(Vector2D(pos.x, pos.y + 1)); // Bas 
	adjacentPositions.push_back(Vector2D(pos.x - 1, pos.y)); // Gauche 
	adjacentPositions.push_back(Vector2D(pos.x + 1, pos.y)); // Droite 

	// Filtrage des cases valides
	std::vector<C_Case*> validPositions;
	for (const auto& pos : adjacentPositions)
	{
		C_Case* adjacentCase = C_Game::Instance->Terrain.GetCase(pos.x, pos.y);

		if (adjacentCase != nullptr
			&& adjacentCase->entity != nullptr) // Vérifie qu'il n'y a pas d'entité sur la case
		{
			validPositions.push_back(adjacentCase);  // Ajouter la position valide
		}
	}
	return validPositions;
}



