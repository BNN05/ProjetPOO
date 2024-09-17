#pragma once
#include "Vector2D.h"
#include "string"

class C_Entity
{
public:
	Vector2D position;
	std::string sprite;
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

