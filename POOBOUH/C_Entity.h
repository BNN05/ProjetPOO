#pragma once
#include "Vector2D.h"
#include "string"
#include "IEventListener.h"
#include <vector>

class C_Entity
{
public:
	Vector2D position;
	std::string sprite;
	int health;
	int currentHealth;
	int attackPoints;
	int currentAttackPoints;
	int movementPoints;
	bool shouldPlay;

	virtual std::string GetSprite() {
		return sprite;
	}
	virtual int GetHealth() {
		return health;
	}
	virtual int GetAttackPoint() {
		return attackPoints;
	}
	virtual int GetMovementPoint() {
		return movementPoints;
	}	
	virtual bool ShouldPlay() {
		return shouldPlay;
	}
	C_Entity(int health = 100, int attackPoints = 10, int movementPoints = 5)
		: health(health), attackPoints(attackPoints), movementPoints(movementPoints), shouldPlay(false)
	{
	}

	virtual void Init() {};
	virtual void OnEnterState() {};
	virtual void ComputeState() {};
	virtual void OnExitState() {};

	virtual bool CanMove();
	virtual bool CanAttack();

	virtual void Move(Vector2D newPos);
	virtual void Attack() {};
	virtual void EndTurn() {};

	void AddListener(IEventListener* listener);
	void RemoveListener(IEventListener* listener);

private:
	std::vector<IEventListener*> listeners;

};

