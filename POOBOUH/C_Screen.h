#pragma once
#include <vector>
#include "C_Widget.h"

class C_Screen
{
public:
	
	C_Widget* enemyWidgets[5];
	C_Widget* playerWidget;

	void DrawEnemyScreen();
	void DrawPlayerScreen();
};

