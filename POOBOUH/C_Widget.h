#pragma once
#include <iostream>
#include "C_Entity.h"

class C_Widget {
public:
    C_Widget(const C_Entity& entity);
    void displayStats() const;
    const C_Entity& entity;
};
