#include "C_Screen.h"
#include "C_Widget.h"
#include "C_Player.h"
#include "C_Game.h"


void C_Screen::DrawEnemyScreen()
{
    auto potentialCase = C_Game::Instance->Terrain.GetAdjacentCase(C_Game::Instance->Player->position);
    vector<C_Entity*> enemies{ };
    for (auto i : potentialCase)
    {
        if (i->entity != nullptr) {
            enemies.push_back(i->entity);
        }
        else
            enemies.push_back(nullptr);
    }

    for (int i = 3; i >=0; i--)
    {
        if (enemies.size() <= i) {
            std::cout << "\n";
            continue;
        }
        if (enemies[i] == nullptr)
            std::cout << "nullptr" << std::endl; //pour debug
        else
            enemyWidgets[i]->displayStats(enemies[i]);
    }
}

void C_Screen::DrawPlayerScreen()
{
    if (C_Game::Instance->Player == nullptr)
        return;
    playerWidget->displayStats(C_Game::Instance->Player);
    std::cout << u8"𝒜 𝓉𝓉𝒶𝒸𝓀 (𝘚𝘱𝘢𝘤𝘦𝘣𝘢𝘳) " << "| " << u8"𝒮𝓀𝒾𝓅 𝒯𝓊𝓇𝓃 (𝘌𝘯𝘵𝘦𝘳) " << std::endl;
}


