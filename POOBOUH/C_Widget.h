#pragma once
#include <iostream>
#include "C_Entity.h"

class C_Widget {
public:
    C_Widget() = default;
    void displayStats(C_Entity* entity) const;
    const C_Entity& entity;
};
