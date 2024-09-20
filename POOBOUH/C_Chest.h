#pragma once
#include <string>
#include "C_Monster.h"
class C_Chest : public C_Monster
{
public:
	std::string sprite;
	int health;
	int attackPoints;
	int movementPoints;
	bool shouldPlay;

	std::string GetSprite() override {
		return sprite;
	}
	int GetHealth() override {
		return health;
	}
	int GetCurrentHealth() override {
		return 100;
	}
	int GetAttackPoint() override {
		return attackPoints;
	}	
	 bool GetInvincible() override {
		return true;
	}
	int GetMovementPoint() override {
		return movementPoints;
	}
	bool ShouldPlay() override {
		return shouldPlay;
	}

	void Init() override;
	void ComputeState() override;
	void OnEnterState() override;

	void OnTakeDamage(int dmg) override;



	C_Chest()
		: C_Monster(100, 10), // Appel du constructeur de C_Monster
		sprite("default_sprite"),
		movementPoints(5),
		shouldPlay(false)
	{
		shouldTakeDmgAll = false;
	}
};
