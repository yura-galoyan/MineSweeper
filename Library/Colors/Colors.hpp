#include "ncurses.h"

using colorType = int;

class COLOR{

public:

    const colorType color = 1;
    colorType fontColor;
    colorType backgroundColor;

public:
    COLOR(colorType ,colorType );

    void startColor(WINDOW*);
    void endColor(WINDOW*);

    ~COLOR();
};