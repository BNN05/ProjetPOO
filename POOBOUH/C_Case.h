#pragma once
#include "C_Entity.h"
#include "Vector2D.h"
#include "E_CaseType.h"
#include "string"

class C_Case
{
public:
	C_Entity* entity;
	Vector2D position;
	std::string sprite;
	E_CaseType caseType;

	void Init(std::string sprite,Vector2D pos);

	C_Case();
	virtual ~C_Case();
};

