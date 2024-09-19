#include "C_Player.h"
#include "C_Game.h"

#include "C_Case.h"
#include "C_EmptyCase.h"



void C_Player::Init()
{
    C_Player::sprite = "P";
    C_Player::health = 7;
    C_Player::currentHealth = C_Player::health;
    C_Player::attackPoints = 3;
    C_Player::movementPoints = 3;
    C_Player::shouldPlay = true;
    C_Player::attackMultiplier = 1;
    shouldTakeDmgAll = false;
}

void C_Player::OnEnterState()
{
    C_Entity::OnEnterState();
    C_Player::ComputeState();
}


void C_Player::ComputeState()
{
    bool skipTurn = false;
    C_Game::Instance->Draw();

    while (CanMove() && CanAttack())
    {
        if (skipTurn)
            break;

        bool shouldDraw = true;

        switch (C_Game::Instance->InputListener.GetKey())
        {
        case E_Key::KeyUp:
            TryMove(E_Direction::Up);
            break;
        case E_Key::KeyDown:
            TryMove(E_Direction::Down);
            break;
        case E_Key::KeyLeft:
            TryMove(E_Direction::Left);
            break;
        case E_Key::KeyRight:
            TryMove(E_Direction::Right);
            break;
        case E_Key::KeyAttack:
            TryAttack();
            break;
        case E_Key::KeySkipTurn:
            OnExitState();
            return;
        default:
            shouldDraw = false;
            break; // No valid key pressed
        }
        if (shouldDraw)
            C_Game::Instance->Draw();
        if (C_Game::Instance->Terrain.EntityManager.Entities.size() == 2) {
            C_Game::Instance->Terrain.LoadNextMap();
            break;
        }
    }

    C_Player::OnExitState();
}

void C_Player::OnExitState()
{
}

int C_Player::GetAttackMultiplier()
{
    return attackMultiplier;
}


void C_Player::TryMove(E_Direction direction)
{
    Vector2D newPosition = position;

    switch (direction)
    {
    case E_Direction::Up:
        newPosition.x -= 1;
        break;
    case E_Direction::Down:
        newPosition.x += 1;
        break;
    case E_Direction::Right:
        newPosition.y += 1;
        break;
    case E_Direction::Left:
        newPosition.y -= 1;
        break;
    default:
        break;
    }

    // Check if the new position is valid
    C_Case* adjacentCase = C_Game::Instance->Terrain.GetCase(newPosition.x, newPosition.y);

    if (adjacentCase != nullptr
        && adjacentCase->caseType == E_CaseType::Empty // Check if it's an EmptyCase
        && adjacentCase->entity == nullptr) // Check if there's no entity on the case
    {
        // Move the player to the new valid position
        Move(newPosition);
        C_Entity::currentMovementPoint -= 1;
    }
}

void C_Player::TryAttack()
{
    if (currentAttackPoints > 0)
    {
        auto potentialCase = C_Game::Instance->Terrain.GetAdjacentCase(C_Game::Instance->Player->position);

        for (auto i : potentialCase)
        {
            if (i->entity != nullptr) {
                Attack(i->entity);
                C_Game::Instance->Terrain.ComputeEntity();
            }
        }
    }
}

void C_Player::Attack(C_Entity* entity)
{
    entity->OnTakeDamage(1 * attackMultiplier);
    currentAttackPoints -= 1;
}

void C_Player::OnTakeDamage(int dmg)
{

        currentHealth -= dmg;

}

void C_Player::OnDeath()
{
    C_Game::Instance->Terrain.LoadGameOver();
}



void C_Player::Move(Vector2D newPos)
{
    C_Game::Instance->Terrain.OnMove(position, newPos);
}
