#include "C_EntityManager.h"
#include <conio.h>

void C_EntityManager::ComputeEntities()
{
    for (auto i : C_EntityManager::Entities)
    {
        i->OnEnterState(); 

    }
    _getch();
}

void C_EntityManager::AddEntity(C_Entity* entity)
{
    Entities.push_back(entity);
}
