#pragma once
#include "C_Entity.h"
#include "Vector2D.h"
#include "E_CaseType.h"

class C_Case
{
public:
	C_Entity* entity;
	Vector2D position;
	char sprite;
	E_CaseType caseType;
};

