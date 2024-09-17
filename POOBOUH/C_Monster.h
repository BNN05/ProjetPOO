#pragma once
#include "C_Entity.h"

class C_Monster : public C_Entity
{
public:
	void OnEnterState() override;
	void ComputeState() override;
	void OnExitState() override;

	bool CanMove() override;
	bool CanAttack() override;

	void Move(Vector2D newPos) override;
	void Attack() override;
	void EndTurn() override;

	
};

