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
	int attackPoints;
	int movementPoints;
	int attackMultiplier;

	bool shouldPlay;
	bool shouldTakeDmgAll = true;
	bool isAlreadyDead = false;
	bool isInvincible = false;

	int currentHealth;
	int currentAttackPoints;
	int currentMovementPoint;

	virtual std::string GetSprite() {
		return sprite;
	}
	virtual int GetHealth() {
		return health;
	}
	virtual int GetCurrentHealth() {
		return currentHealth;
	}
	virtual void SetCurrentHealth(int health) {
		currentHealth = health;
	}
	virtual int GetCurrentAttackPoints() {
		return currentAttackPoints;
	}
	virtual int GetCurrentMovementPoints() {
		return currentMovementPoint;
	}
	virtual int GetAttackPoint() {
		return attackPoints;
	}	
	virtual bool GetInvincible() {
		return isInvincible;
	}

	virtual void SetAttackMultiplier(int aM) { attackMultiplier = aM; }

	virtual int GetAttackMultiplier() {
		return 1;
	}
	virtual int GetMovementPoint() {
		return movementPoints;
	}	
	virtual bool ShouldPlay() {
		return shouldPlay;
	}
	C_Entity(int health = 5, int attackPoints = 5, int movementPoints = 5)
		: health(health), attackPoints(attackPoints), movementPoints(movementPoints), shouldPlay(false)
	{
		currentHealth = health;
		currentAttackPoints = attackPoints;
		currentMovementPoint = movementPoints;
	}

	virtual void Init() {};
	virtual void OnEnterState();
	virtual void ComputeState() {};
	virtual void OnExitState() {};

	virtual void OnTakeDamage(int dmg) {};
	virtual void OnDeath() {};

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

