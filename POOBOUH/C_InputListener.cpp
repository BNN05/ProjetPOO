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
        //cout << "Up" << endl;
        return E_Key::KeyUp;
    case KEY_DOWN:
        //cout << "Down" << endl;
        return E_Key::KeyDown;
    case KEY_LEFT:
        //cout << "Left" << endl;
        return E_Key::KeyLeft;
    case KEY_RIGHT:
        //cout << "Right" << endl;
        return E_Key::KeyRight;
    case KEY_ATTACK:
        //cout << "Attack" << endl;
        return E_Key::KeyAttack;
    default:
        //cout << "Key not bind " << endl;
        return E_Key::KeyOther;
    }

}
