#pragma once
#include "C_Monster.h"

class C_Chest : public C_Monster
{
public:
    C_Chest() : C_Monster(100, 0, 0, u8"🟫") {}

    void Init() override { C_Monster::Init(); }

    void OnTakeDamage(int dmg) override;
    void OnDeath() override;
};