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
	bool shouldPlay;
	 

	virtual void OnEnterState();
	virtual void ComputeState();
	virtual void OnExitState();

	virtual bool CanMove();
	virtual bool CanAttack();

	void Move(Vector2D newPos);
	void Attack();
	void EndTurn();

	void AddListener(IEventListener* listener);
	void RemoveListener(IEventListener* listener);

private:
	std::vector<IEventListener*> listeners;
	Vector2D position;

};

