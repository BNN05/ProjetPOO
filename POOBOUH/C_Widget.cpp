#include "C_Widget.h"


void C_Widget::displayStats(C_Entity* entity) const {


    for (int i = 0; i < entity->currentHealth; ++i) {
        std::cout << u8"❤️";
    }    
    std::cout << " | ";

    for (int i = 0; i < entity->currentAttackPoints; ++i) {
        std::cout << u8"⚔️";
    }

    std::cout << std::endl;
}
