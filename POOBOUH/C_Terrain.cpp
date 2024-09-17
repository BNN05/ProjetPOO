#include "C_Terrain.h"
#include <iostream>
#include "Windows.h"
#include <string>
#include "C_TerrainLoader.h"

void C_Terrain::GenerateMap()
{
	C_TerrainLoader terrainLoader;
	auto v = terrainLoader.LoadMap("MapFiles/Level1.csv");	
	
	for (int i = 0; i < C_Terrain::lengthX; i++) {
		for (int j = 0; j < C_Terrain::lengthY; j++) {
			C_Case* tile = new C_Case();
			if (v[i][j] != u8"🟦") {
				//TODO : Gestion entité
				tile->Init(u8"🟩", Vector2D(i, j));

			}
			else
				tile->Init(v[i][j], Vector2D(i, j));
			this->map[i][j] = tile;
		}
	}
}

void C_Terrain::DrawTerrain()
{

	for (int i = 0; i < C_Terrain::lengthX; i++) {
		for (int j = 0; j < C_Terrain::lengthY; j++) {
			if(C_Terrain::map[i][j]->entity != nullptr)
				std::cout << C_Terrain::map[i][j]->entity->sprite;
			else
				std::cout << C_Terrain::map[i][j]->sprite;
		}
		std::cout << "\n";
	}
}

C_Terrain::C_Terrain() : lengthX(0), lengthY(0), map(nullptr) {

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
