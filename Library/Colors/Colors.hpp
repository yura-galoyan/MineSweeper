#pragma once
#include <ncurses.h>

using colorType = int;

class COLOR{

private:
    const colorType backGround = -1;
    colorType color;

public:
    COLOR(colorType, colorType  );

    void startColor(WINDOW*);
    void endColor(WINDOW*);

    operator int(){
        return color;
    }

    ~COLOR();
};