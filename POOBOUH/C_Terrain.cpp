#include "C_Terrain.h"
#include <iostream>
#include "Windows.h"
#include <string>
#include "C_TerrainLoader.h"
#include "C_Golem.h"
#include "C_Spectre.h"
#include "C_Reaper.h"
#include "C_Player.h"

void C_Terrain::OnMove(Vector2D oldPosition,Vector2D newPosition) {
	if (map[(int)oldPosition.x][(int)oldPosition.y]->entity == nullptr)
		return;
	if (map[(int)newPosition.x][(int)newPosition.y]->entity != nullptr)
		return;


	map[(int)newPosition.x][(int)newPosition.y]->AddEntity(map[(int)oldPosition.x][(int)oldPosition.y]->entity);
	map[(int)oldPosition.x][(int)oldPosition.y]->entity = nullptr;

}
void C_Terrain::GenerateMap()
{
	C_TerrainLoader terrainLoader;
	auto v = terrainLoader.LoadMap("MapFiles/Level1.csv");	
	
	for (int i = 0; i < C_Terrain::lengthX; i++) {
		for (int j = 0; j < C_Terrain::lengthY; j++) {
			C_Case* tile = new C_Case();
			if (v[i][j] != u8"🟫") { //Carré marron
				tile->Init(u8"🔳", Vector2D(i, j)); //Carré vide
				tile->caseType = E_CaseType::Empty;
				if (v[i][j] != u8"🔳") {//Carré vide
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
					else if ((v[i][j] == "@"))
					{
						C_Player* player = new C_Player();
						player->Init();
						tile->AddEntity(player);
						EntityManager.AddEntity(player);
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

C_Terrain::C_Terrain() : lengthX(0), lengthY(0), map(nullptr),EntityManager() {
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

C_Case* C_Terrain::GetCase(int x, int y)
{
	if (x >= 0 && x < lengthX && y >= 0 && y < lengthY)
	{
		return map[x][y]; // Retourne la case 
	}
	return nullptr; 
}

