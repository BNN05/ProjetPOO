#pragma once
#include <iostream>
#include <conio.h>
#include "E_Key.h"

using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define KEY_ATTACK 97

class C_InputListener
{
public:
    C_InputListener();

    E_Key GetKey();

};