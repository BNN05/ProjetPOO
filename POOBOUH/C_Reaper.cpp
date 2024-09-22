#include "C_Reaper.h"
#include "C_Game.h"

void C_Reaper::OnDeath()
{
    // Dégats à tout les ennemies dans la salle
    if (isAlreadyDead)
        return;
    isAlreadyDead = true;
    C_Game::Instance->Terrain.EntityManager.HitAllEntity(2);
}


void C_Reaper::ComputeState()
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
        auto path = C_Game::Instance->Terrain.GetPath(this->position, C_Game::Instance->Player->position);
        Move(path[0]->position);
        currentMovementPoint--;
    }

    
}