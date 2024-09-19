#include "C_Reaper.h"
#include "C_Game.h"



void C_Reaper::Init()
{
    C_Reaper::sprite = u8"🕷️";
    C_Reaper::health = 2;
    C_Reaper::attackPoints = 2;
    C_Reaper::movementPoints = 3;
    C_Reaper::shouldPlay = true;
    currentHealth = C_Reaper::health;
}

void C_Reaper::ComputeState()
{

    auto path = C_Game::Instance.Terrain.GetPath(this->position, C_Game::Instance.Player->position);
    Move(path[0]->position);
}

void C_Reaper::OnEnterState()
{
    C_Reaper::currentAttackPoints = attackPoints;
    C_Reaper::currentMovementPoint = movementPoints;
    C_Reaper::ComputeState();

    C_Reaper::ComputeState();
}
bool C_Reaper::CanMove()
{
    if (C_Reaper::currentMovementPoint > 0)
        return true;
    return false;
}

