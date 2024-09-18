#include "C_Player.h"
#include "C_Game.h"

#include "C_Case.h"
#include "C_EmptyCase.h"

void C_Player::OnEnterState()
{
    C_Player::ComputeState();
}


void C_Player::ComputeState()
{
    if (CanMove())
    {
        Vector2D newPosition = position;

        switch (C_Game::Instance.InputListener.GetKey())
        {
        case E_Key::Up:
            newPosition.y -= 1;
            break;
        case E_Key::Down:
            newPosition.y += 1;
            break;
        case E_Key::Left:
            newPosition.x -= 1;
            break;
        case E_Key::Right:
            newPosition.x += 1;
            break;
        default:
            return; // No valid key pressed
        }

        // Check if the new position is valid
        C_Case* adjacentCase = C_Game::Instance.Terrain.GetCase(newPosition.x, newPosition.y);

        if (adjacentCase != nullptr
            && dynamic_cast<C_EmptyCase*>(adjacentCase) // Check if it's an EmptyCase
            && adjacentCase->entity == nullptr) // Check if there's no entity on the case
        {
            // Move the player to the new valid position
            Move(newPosition);
        }
    }
}


void C_Player::Move(Vector2D newPos)
{

}
