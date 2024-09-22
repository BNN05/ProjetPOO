#pragma once
#include "C_Entity.h"

class C_Monster : public C_Entity
{
public:
    C_Monster(int health, int attackPoints, int movementPoints, const std::string& sprite)
        : C_Entity(health, attackPoints, movementPoints)
    {
        this->sprite = sprite;
    }

    virtual void Init() override {}
    virtual void OnEnterState() override;
    virtual void OnExitState() override;

    virtual void Move(Vector2D newPos) override;
    virtual void Attack() override {}
    virtual void EndTurn() override {}

    virtual void OnTakeDamage(int dmg) override;
    virtual void OnDeath() override;
};
