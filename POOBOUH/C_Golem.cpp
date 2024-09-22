#include "C_Golem.h"
#include <cstdlib>
#include "C_Game.h"
#include <ctime>
#include <random>

void C_Golem::OnTakeDamage(int dmg)
{
    std::srand(std::time(0));
    int randomValue = std::rand() % 3;
    if (randomValue != 0) {
        C_Monster::OnTakeDamage(dmg);
    }
}

void C_Golem::ComputeState()
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
        if (CanMove())
        {
            std::vector<Vector2D> adjacentPositions;

            adjacentPositions.push_back(Vector2D(position.x, position.y - 1)); // Haut
            adjacentPositions.push_back(Vector2D(position.x, position.y + 1)); // Bas
            adjacentPositions.push_back(Vector2D(position.x - 1, position.y)); // Gauche
            adjacentPositions.push_back(Vector2D(position.x + 1, position.y)); // Droite

            std::vector<Vector2D> validPositions;
            for (const auto& pos : adjacentPositions)
            {
                C_Case* adjacentCase = C_Game::Instance->Terrain.GetCase(pos.x, pos.y);

                if (adjacentCase != nullptr
                    && adjacentCase->caseType == E_CaseType::Empty 
                    && adjacentCase->entity == nullptr) 
                {
                    validPositions.push_back(pos);  
                }
            }

            if (!validPositions.empty())
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, validPositions.size() - 1);

                Vector2D newPosition = validPositions[dis(gen)];

                Move(newPosition);

                currentMovementPoint--;

            }

        }
    }


    OnExitState();
}

void C_Golem::OnDeath()
{
    // Augmente l'attaque du player
    C_Game::Instance->Player->SetAttackMultiplier(C_Game::Instance->Player->GetAttackMultiplier() + 1);
}
