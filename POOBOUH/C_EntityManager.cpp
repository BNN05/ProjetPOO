#include "C_EntityManager.h"
#include <conio.h>
#include "C_Game.h"

void C_EntityManager::ComputeEntities()
{
   int  j = 0;
    for (auto i : C_EntityManager::Entities)
    {
        if (shouldStopProcessEntity) {
            shouldStopProcessEntity = false;
            return;
        }
        i->OnEnterState(); 
        j++;
    }
    //_getch();
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
void C_EntityManager::RemoveAllEntity()
{
    for (int i = C_EntityManager::Entities.size() - 1; i >= 0; i--)
    {
            DeleteEntity(C_EntityManager::Entities[i]);
        
    }
}
void C_EntityManager::AddPlayer(C_Entity* entity)
{
    Entities.insert(Entities.end(), entity);
}

void C_EntityManager::CheckForEntityAlive()
{
    for (int i = C_EntityManager::Entities.size()-1; i >= 0; i--)
    {
        //if (C_EntityManager::Entities.size() == 2 && C_EntityManager::Entities[0] == C_Game::Instance->Player) {
        //    C_Game::Instance->Terrain.LoadNextMap();
        //    return;
        //}
        int ttt = C_EntityManager::Entities[i]->GetCurrentHealth();
        if ( ttt<= 0) {
            C_EntityManager::Entities[i]->OnDeath();
            if (C_EntityManager::Entities.size() <= 0)
                return;
            DeleteEntity(C_EntityManager::Entities[i]);
        }
    }
     C_Game::Instance->Draw();
    //for (auto i : C_EntityManager::Entities)
    //{
    //    if (i->GetCurrentHealth() <= 0) {
    //        i->OnDeath();
    //        DeleteEntity(i);
    //        C_Game::Instance->Draw();
    //    }

    //}
}
void C_EntityManager::CheckForEntityToRemove()
{
    for (int i = C_EntityManager::Entities.size() - 1; i >= 0; i--)
    {
        int ttt = C_EntityManager::Entities[i]->GetCurrentHealth();
        if (ttt <= 0) {
            DeleteEntity(C_EntityManager::Entities[i]);
        }
    }
    C_Game::Instance->Draw();
}

void C_EntityManager::HitAllEntity(int dmg)
{
    for (auto i : C_EntityManager::Entities)
    {
        if (i->shouldTakeDmgAll)
            i->OnTakeDamage(dmg);
    }
    CheckForEntityToRemove();
}




