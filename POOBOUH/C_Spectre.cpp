#include "C_Spectre.h"
#include "C_Game.h"
#include <random>

void C_Spectre::OnDeath()
{
    // Heal le joueur à sa mort
    C_Game::Instance->Player->SetCurrentHealth(C_Game::Instance->Player->GetHealth());
}


void C_Spectre::ComputeState()
{
    while (CanMove())
    {
        if (CanAttack())
        {
            auto potentialCase = C_Game::Instance->Terrain.GetAdjacentCase(position);
            for (auto e : potentialCase)
            {
                if (e->entity != nullptr && e->entity == C_Game::Instance->Player) {
                    e->entity->OnTakeDamage(1);
                    C_Game::Instance->Terrain.ComputeEntity();
                    if (C_Game::Instance->isOver) { //regarde si il ne reste que le player 
                        return;
                    }
                    currentAttackPoints--;
                    return;
                }
            }
        }
        auto path = C_Game::Instance->Terrain.FleePath(this->position, C_Game::Instance->Player->position,currentMovementPoint);
        if(path.size()>0)
            Move(path[0]->position);
        currentMovementPoint--;
    }
}
