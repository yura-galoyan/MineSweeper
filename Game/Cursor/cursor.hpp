#include <iostream>
#include <ncurses.h>
#include <utility>
#include "../../Library/Types/types.hpp"
constexpr auto CURS_COLOR = 1;
using Cell = pair<int,bool>;
using Coords = std::pair<unsigned,unsigned>;

class CURSOR{


public:
    enum action{ left = 'a',right = 'd',up = 'w',down = 's',open = 'o',mark = 'm'};  

public:
    CURSOR(unsigned, unsigned);

public:
    void cursorColor_begin(); // makes cursor green
    void setCursorPosition(Coords);
    void setCursorWin(window,Coords);
    Coords getCursorPosition();
    void placeCursor(); // creates cursor at cords
    void eraseCursor(); // erases cursor at latest cords
    void move(const int& key); // CURSOR::left, CURSOR::right, CURSOR::up, CURSOR::down
    void putFlag(); // player puts flag,to remember that there might be a bomb
    void demine();  // player tries to demine a bomb
    
    bool canTouch(Cell); // checks if cell isn't CURSOR::open

private:
    int i,j;
    window map;
    unsigned maxx,maxy; //coordinates
private:
    bool state; // shows if cell is CURSOR::opened or closed
};