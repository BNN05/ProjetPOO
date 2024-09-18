#include "C_Screen.h"
#include "C_Widget.h"
#include "C_Player.h"
#include "C_Game.h"


void C_Screen::DrawEnemyScreen()
{
    for (size_t i = 1; i < 6; i++)
    {
        if (enemyWidgets[i] == nullptr)
            std::cout << "nullptr" << std::endl; //pour debug
        else
            enemyWidgets[i]->displayStats(C_Game::Instance.Terrain.EntityManager.Entities[i]);
    }
}

void C_Screen::DrawPlayerScreen()
{
    playerWidget->displayStats(C_Game::Instance.Player);
}


