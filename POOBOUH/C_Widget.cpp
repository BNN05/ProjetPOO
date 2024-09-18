#include "C_Widget.h"

C_Widget::C_Widget(const C_Entity& entity)
    : entity(entity) {}

void C_Widget::displayStats() const {

    std::cout << "\n" << "entity.name" << " : ";

    for (int i = 0; i < entity.currentHealth; ++i) {
        std::cout << u8"❤️";
    }    
    std::cout << "  ";

    for (int i = 0; i < entity.currentAttackPoints; ++i) {
        std::cout << u8"⚔️";
    }

    std::cout << std::endl;
}
