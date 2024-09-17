#pragma once
#include "Vector2D.h"

class C_Entity
{
public:
	Vector2D position;
	char sprite;
	int health;
	int attackPoints;
	int movementPoints;
	bool shouldPlay;
	 

	void OnEnterState();
	void ComputeState();
	void OnExitState();

	bool CanMove();
	bool CanAttack();

	void Move();
	void Attack();
	void EndTurn();

};

