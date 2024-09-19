#include "C_Widget.h"


void C_Widget::displayStats(C_Entity* entity) const {

    std::cout << entity->GetSprite() << ": ";

    for (int i = 0; i < entity->GetHealth(); ++i) {
        
        if (i < entity->GetCurrentHealth())
            std::cout << u8"❤️";
        else
            std::cout << u8"🖤";
    }    
    std::cout << " | ";

    for (int i = 0; i < entity->GetAttackPoint(); ++i) {
        
        if (i < entity->GetCurrentAttackPoints())
            std::cout << u8"⚔️";
        else
            std::cout << u8"🕳️";
    }

    std::cout << std::endl;
}
