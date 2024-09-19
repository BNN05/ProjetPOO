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
    C_Monster::ComputeState();
}

void C_Monster::ComputeState()
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
        }

    }


    C_Monster::OnExitState();
}

void C_Monster::OnExitState()
{
    C_Game::Instance->Draw();
}

void C_Monster::Move(Vector2D newPos)
{
    C_Game::Instance->Terrain.OnMove(position, newPos);
}

