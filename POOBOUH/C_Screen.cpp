#include "C_Screen.h"
#include "C_Widget.h"


void C_Screen::DrawScreen()
{
    for (size_t i = 1; i < 5; i++)
    {
        if (widgets[i] == nullptr)
            std::cout << std::endl;
        else
            widgets[i]->displayStats();
    }
}
