#pragma once
#include "Vector2D.h"
class IEventListener {
public:
    virtual ~IEventListener() = default;
    virtual void OnMove(Vector2D newPosition) = 0; // M�thode d'�v�nement
};

