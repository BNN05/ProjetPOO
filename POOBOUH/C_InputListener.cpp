#include "C_InputListener.h"

C_InputListener::C_InputListener()
{

}

E_Key C_InputListener::GetKey()
{

    int c;

    c = _getch();

    if (c == 224)
        c = _getch();
    
    switch (c)
    {
    case KEY_UP:
        cout << "Up" << endl;
        return E_Key::Up;
    case KEY_DOWN:
        cout << "Down" << endl;
        return E_Key::Down;
    case KEY_LEFT:
        cout << "Left" << endl;
        return E_Key::Left;
    case KEY_RIGHT:
        cout << "Right" << endl;
        return E_Key::Right;
    case KEY_ATTACK:
        cout << "Attack" << endl;
        return E_Key::Attack;
    default:
        cout << "Key not bind " << endl;
        return E_Key::OtherKey;
    }

}
