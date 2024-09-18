#include "C_Widget.h"


void C_Widget::displayStats(C_Entity* entity) const {


    for (int i = 0; i < entity->GetHealth(); ++i) {
        std::cout << u8"❤️";
    }    
    std::cout << " | ";

    for (int i = 0; i < entity->GetAttackPoint(); ++i) {
        std::cout << u8"⚔️";
    }

    std::cout << std::endl;
}
