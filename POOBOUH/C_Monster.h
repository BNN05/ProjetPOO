#pragma once
#include "C_Entity.h"

class C_Monster : public C_Entity
{
public:
	void OnEnterState() override;
	void ComputeState() override;
	void OnExitState() override;

	void Move(Vector2D newPos) override;
	void Attack() override {};
	void EndTurn() override {};

	void OnTakeDamage(int dmg) override;
	void OnDeath() override;

	C_Monster(int health, int attackPoints) {
		this->health = health;
		this->attackPoints = attackPoints;
	}


};

