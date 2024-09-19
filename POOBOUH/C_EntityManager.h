#pragma once
#include <vector>
#include "C_Entity.h"
class C_EntityManager
{
public:
	std::vector<C_Entity*> Entities;

	void ComputeEntities();
	void AddEntity(C_Entity* entity);
	void DeleteEntity(C_Entity* entity);

	void AddPlayer(C_Entity* entity);
	void CheckForEntityAlive();

	C_EntityManager() = default;
};

