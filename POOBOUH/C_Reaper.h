#pragma once
#include "C_Monster.h"

class C_Reaper : public C_Monster
{
public:
    C_Reaper() : C_Monster(2, 2, 3, u8"🕷️") {}

    void Init() override {
        C_Monster::Init();
        shouldTakeDmgAll = false;
    }

    void ComputeState() override;

    void OnDeath() override;
};
