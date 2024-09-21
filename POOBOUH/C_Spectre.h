#pragma once
#include "C_Monster.h"

class C_Spectre : public C_Monster
{
public:
    C_Spectre() : C_Monster(3, 2, 3, u8"👻") {}

    void Init() override { C_Monster::Init(); }

    void OnDeath() override;
    void ComputeState() override;
};
