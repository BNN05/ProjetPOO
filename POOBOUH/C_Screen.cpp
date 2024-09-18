#include "C_Screen.h"
#include "C_Widget.h"
#include "C_Player.h"
#include "C_Game.h"


void C_Screen::DrawEnemyScreen()
{
    auto potentialCase = C_Game::Instance.Terrain.GetAdjacentCase(C_Game::Instance.Player->position);
    vector<C_Entity*> enemies{ };
    for (auto i : potentialCase)
    {
        if (i->entity != nullptr) {
            enemies.push_back(i->entity);
        }
        else
            enemies.push_back(nullptr);
    }

    for (size_t i = 0; i < 5; i++)
    {
        if (enemies.size() <=i)
            return;
        if (enemies[i] == nullptr)
            std::cout << "nullptr" << std::endl; //pour debug
        else
            enemyWidgets[i]->displayStats(enemies[i]);
    }
}

void C_Screen::DrawPlayerScreen()
{
    playerWidget->displayStats(C_Game::Instance.Player);
}


