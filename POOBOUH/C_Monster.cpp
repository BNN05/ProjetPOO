#include "C_Monster.h"
#include <random>
#include <iostream>
#include "C_Game.h"
#include "C_Terrain.h"
#include "C_Case.h"
#include "C_EmptyCase.h"

void C_Monster::OnEnterState()
{
    C_Entity::OnEnterState();
    ComputeState();
}


void C_Monster::OnExitState()
{
	C_Game::Instance->Draw();
}

void C_Monster::Move(Vector2D newPos)
{
	C_Game::Instance->Terrain.OnMove(position, newPos);
    currentMovementPoint--;
}

void C_Monster::OnTakeDamage(int dmg)
{
    currentHealth -= dmg;
    if (currentHealth <= 0)
        OnDeath();
}

void C_Monster::OnDeath()
{
}

