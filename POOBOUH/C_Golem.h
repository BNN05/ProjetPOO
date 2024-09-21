#pragma once
#include "C_Monster.h"

class C_Golem : public C_Monster
{
public:
    C_Golem() : C_Monster(5, 1, 1, u8"🗿") {}

    void Init() override { C_Monster::Init(); }

    void OnTakeDamage(int dmg) override;
    void ComputeState() override;
    void OnDeath() override;
};
