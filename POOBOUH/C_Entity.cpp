#include "C_Entity.h"

void C_Entity::OnEnterState()
{
    currentAttackPoints = attackPoints;
    currentMovementPoint = movementPoints;
    currentHealth = health;
}

bool C_Entity::CanMove()
{
    if (C_Entity::currentMovementPoint > 0)
        return true;
    return false;
}

bool C_Entity::CanAttack()
{
    if (C_Entity::attackPoints > 0)
        return true;
    return false;
}

void C_Entity::Move(Vector2D newPos)
{
    //position = newPos;
    //// Notifie tous les écouteurs de l'événement de déplacement
    //for (IEventListener* listener : listeners) {
    //    listener->OnMove(newPos);
    //}
}

void C_Entity::AddListener(IEventListener* listener) {
    listeners.push_back(listener);
}

void C_Entity::RemoveListener(IEventListener* listener) {
    auto it = std::remove(listeners.begin(), listeners.end(), listener);
    listeners.erase(it, listeners.end());
}

