#pragma once
#include "C_Entity.h"
#include "E_Direction.h"

class C_Player : public C_Entity
{
public:
	C_Player() = default;

	void OnEnterState() override;
	void ComputeState() override;
	void OnExitState() override;

	void Init() override;

	void TryMove(E_Direction direction);
	void TryAttack();

	void Attack(C_Entity* entity);


	void Move(Vector2D newPos);

	int currentMovementPoints;
	int attackMultiplier;

};

