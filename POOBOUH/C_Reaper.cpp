#include "C_Reaper.h"
#include "C_Game.h"
#include <chrono>
#include <thread>



void C_Reaper::Init()
{
    C_Reaper::sprite = u8"🕷️";
    C_Reaper::health = 2;
    C_Reaper::attackPoints = 2;
    C_Reaper::movementPoints = 3;
    C_Reaper::shouldPlay = true;
    currentHealth = C_Reaper::health;
    shouldTakeDmgAll = false;
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
                    e->entity->OnTakeDamage(1 );
                    C_Game::Instance->Terrain.ComputeEntity();
                    C_Entity::attackPoints--;
                    return;
                }
            }
        }
        auto path = C_Game::Instance->Terrain.GetPath(this->position, C_Game::Instance->Player->position);
        Move(path[0]->position);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        C_Reaper::currentMovementPoint--;
    }
}
void C_Reaper::OnDeath()
{
    if (isAlreadyDead)
        return;
    isAlreadyDead = true;
    C_Game::Instance->Terrain.EntityManager.HitAllEntity(2);
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

