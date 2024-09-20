#include "C_Chest.h"

void C_Chest::Init()
{
    C_Chest::sprite = u8"🟫";
    C_Chest::health = 1;
    C_Chest::attackPoints = 0;
    C_Chest::movementPoints = 0;
    C_Chest::shouldPlay = false;
}

void C_Chest::ComputeState()
{
}

void C_Chest::OnEnterState()
{
}

void C_Chest::OnTakeDamage(int dmg)
{
}
