#pragma once
#include <ncurses.h>

using colorType = int;

class COLOR{

private:
    const colorType backGround = -1;
    const colorType color = 2;

public:
    COLOR(colorType  );

    void startColor(WINDOW*);
    void endColor(WINDOW*);

    ~COLOR();
};