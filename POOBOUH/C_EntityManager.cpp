#include "C_EntityManager.h"
#include <conio.h>
#include "C_Game.h"

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
void C_EntityManager::DeleteEntity(C_Entity* entity)
{
    C_Game::Instance->Terrain.GetCaseByEntity(entity)->entity = nullptr;
    Entities.erase(std::remove(Entities.begin(), Entities.end(), entity), Entities.end());
    delete entity;
}
void C_EntityManager::AddPlayer(C_Entity* entity)
{
    Entities.insert(Entities.begin(), entity);
}

void C_EntityManager::CheckForEntityAlive()
{
    for (auto i : C_EntityManager::Entities)
    {
        if (i->GetCurrentHealth() <= 0) {
            DeleteEntity(i);
            C_Game::Instance->Draw();
        }

    }
}




