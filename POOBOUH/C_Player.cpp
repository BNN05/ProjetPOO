#include "C_Player.h"
#include "C_Game.h"

#include "C_Case.h"
#include "C_EmptyCase.h"

void C_Player::OnEnterState()
{
    currentMovementPoints = movementPoints;
    C_Player::ComputeState();
}


void C_Player::ComputeState()
{
    bool skipTurn = false;

    while (CanMove() && CanAttack())
    {
        if (skipTurn)
            break;

        switch (C_Game::Instance.InputListener.GetKey())
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
        default:
            return; // No valid key pressed
        }
        C_Game::Instance.Draw();
    }

    C_Player::OnExitState();
}

void C_Player::OnExitState()
{
}


void C_Player::TryMove(E_Direction direction)
{
    Vector2D newPosition = position;

    switch (direction)
    {
    case E_Direction::Up:
        newPosition.y -= 1;
        break;
    case E_Direction::Down:
        newPosition.y += 1;
        break;
    case E_Direction::Right:
        newPosition.x += 1;
        break;
    case E_Direction::Left:
        newPosition.x -= 1;
        break;
    default:
        break;
    }

    // Check if the new position is valid
    C_Case* adjacentCase = C_Game::Instance.Terrain.GetCase(newPosition.x, newPosition.y);

    if (adjacentCase != nullptr
        && dynamic_cast<C_EmptyCase*>(adjacentCase) // Check if it's an EmptyCase
        && adjacentCase->entity == nullptr) // Check if there's no entity on the case
    {
        // Move the player to the new valid position
        Move(newPosition);
        currentMovementPoints -= 1;
    }
}

void C_Player::TryAttack()
{
}

void C_Player::Move(Vector2D newPos)
{
    C_Game::Instance.Terrain.OnMove(position, newPos);
}
