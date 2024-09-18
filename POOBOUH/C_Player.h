#pragma once
#include "C_Entity.h"
class C_Player : public C_Entity
{
public:
	C_Player() = default;

	void OnEnterState() override;
	void ComputeState() override;
	void OnExitState() override;

	bool CanMove() override;
	bool CanAttack() override;

	void Move(Vector2D newPos);
	void Attack() override;
	void EndTurn() override;

	

};

