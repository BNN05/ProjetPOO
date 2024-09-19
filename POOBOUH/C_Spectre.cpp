#include "C_Spectre.h"
#include "C_Case.h"
#include <random>
#include "C_Game.h"
#include <chrono>
#include <thread>
void C_Spectre::Init()
{
    C_Spectre::sprite = "S";
    C_Spectre::health = 3;
    C_Spectre::attackPoints = 2;
    C_Spectre::movementPoints = 3;
    C_Spectre::shouldPlay = true;
    currentHealth = C_Spectre::health;
}

void C_Spectre::OnEnterState()
{
    C_Spectre::currentAttackPoints = attackPoints;
    C_Spectre::currentMovementPoint = movementPoints;
    C_Spectre::ComputeState();
}

void C_Spectre::ComputeState()
{
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
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }


    C_Spectre::OnExitState();
}

bool C_Spectre::CanMove()
{
    if (C_Spectre::currentMovementPoint > 0)
        return true;
    return false;
}

void C_Spectre::OnExitState()
{
    C_Game::Instance->Draw();
}

void C_Spectre::OnDeath()
{
    //Heal le joueur
    C_Game::Instance->Player->SetCurrentHealth(C_Game::Instance->Player->GetHealth());
}
