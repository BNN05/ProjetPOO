#pragma once
#include <vector>
#include "C_Entity.h"
class C_EntityManager
{
public:
	std::vector<C_Entity*> Entities;

	void ComputeEntities();
	void AddEntity(C_Entity* entity);

	C_EntityManager() = default;
};

