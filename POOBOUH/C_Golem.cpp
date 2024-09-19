#include "C_Golem.h"
#include "C_Case.h"
#include <random>
#include "C_Game.h"



void C_Golem::Init()
{
    C_Golem::sprite = u8"🗿";
    C_Golem::health = 5;
    C_Golem::attackPoints = 1;
    C_Golem::movementPoints = 1;
    C_Golem::shouldPlay = true;
    currentHealth = C_Golem::health;
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
                    C_Entity::attackPoints--;
                    return;
                }
            }
        }
        if (CanMove())
        {
            std::vector<Vector2D> adjacentPositions;

            // Ajout des positions des cases adjacentes
            adjacentPositions.push_back(Vector2D(position.x, position.y - 1)); // Haut
            adjacentPositions.push_back(Vector2D(position.x, position.y + 1)); // Bas
            adjacentPositions.push_back(Vector2D(position.x - 1, position.y)); // Gauche
            adjacentPositions.push_back(Vector2D(position.x + 1, position.y)); // Droite

            // Filtrage des cases valides
            std::vector<Vector2D> validPositions;
            for (const auto& pos : adjacentPositions)
            {
                C_Case* adjacentCase = C_Game::Instance->Terrain.GetCase(pos.x, pos.y);

                // Vérification si la case est de type EmptyCase et qu'elle ne contient pas déjà une entité
                if (adjacentCase != nullptr
                    && adjacentCase->caseType == E_CaseType::Empty // Vérifie que c'est une EmptyCase
                    && adjacentCase->entity == nullptr) // Vérifie qu'il n'y a pas d'entité sur la case
                {
                    validPositions.push_back(pos);  // Ajouter la position valide
                }
            }

            if (!validPositions.empty())
            {
                // Sélection aléatoire d'une case valide
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, validPositions.size() - 1);

                Vector2D newPosition = validPositions[dis(gen)];

                // Déplacer le monstre vers la nouvelle position
                Move(newPosition);

                C_Golem::currentMovementPoint--;
            }

        }
    }


    C_Golem::OnExitState();
}

void C_Golem::OnEnterState()
{
    C_Golem::currentAttackPoints = attackPoints;
    C_Golem::currentMovementPoint = movementPoints;
    C_Golem::ComputeState();

    C_Golem::ComputeState();
}

void C_Golem::OnTakeDamage(int dmg)
{
    std::srand(std::time(0));

    int randomValue = std::rand() % 3;

    if (randomValue == 0) {
        //dont take dmg
    }
    else {
        currentHealth -= dmg;
    }
}

void C_Golem::OnDeath()
{
    C_Game::Instance->Player->SetAttackMultiplier(C_Game::Instance->Player->attackMultiplier + 1);
}

bool C_Golem::CanMove()
{
    if (C_Golem::currentMovementPoint > 0)
        return true;
    return false;
}



