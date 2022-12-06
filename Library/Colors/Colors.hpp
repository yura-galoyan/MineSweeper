#include <ncurses.h>

using colorType = int;

class COLOR{

private:

    const colorType colorDefault = 1;
    const colorType colorGreen = 2;
    colorType fontColor;
    colorType backgroundColor;

public:
    COLOR(colorType ,colorType );

    void startColor(WINDOW*);
    void endColor(WINDOW*);

    ~COLOR();
};