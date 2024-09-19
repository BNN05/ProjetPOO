#pragma once
#include "C_Monster.h"
class C_Golem : public C_Monster
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
	int GetAttackPoint() override {
		return attackPoints;
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

	 void OnTakeDamage(int dmg) override ;
	 void OnDeath() override ;

	bool CanMove() override;


	C_Golem()
		: C_Monster(100, 10), // Appel du constructeur de C_Monster
		sprite("default_sprite"),
		movementPoints(5),
		shouldPlay(false)
	{
	}
};

