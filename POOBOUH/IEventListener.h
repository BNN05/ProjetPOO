#pragma once
#include "Vector2D.h"
class IEventListener {
public:
    virtual ~IEventListener() = default;
    virtual void OnMove(Vector2D newPosition) = 0; // Méthode d'événement
};

