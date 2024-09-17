#include "C_Monster.h"
#include <random>
#include <iostream>
#include "C_Game.h"
#include "C_Terrain.h"
#include "C_Case.h"

void C_Monster::ComputeState()
{
	if (CanMove())
	{
		int direction;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 4);

		// Génération d'un nombre aléatoire
		direction = dis(gen);

		C_Game::Instance.Terrain.GetCase(position.x, position.y);
		
	}

}
