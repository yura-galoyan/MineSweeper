#include <iostream>
#include <ncurses.h>
#include <utility>
#include "../../Library/Types/types.hpp"
#include "../../Library/Colors/Colors.hpp"
constexpr auto CURS_COLOR = 1;
using Cell = pair<int,bool>;
using Coords = std::pair<unsigned,unsigned>;

class CURSOR{
private:
    int i,j;
    window map;
    unsigned maxx,maxy; 

private:
    bool state;

private:

COLOR white{COLOR_WHITE},
      red{COLOR_RED},
      yellow{COLOR_YELLOW},
      green{COLOR_GREEN},
      magenta{COLOR_MAGENTA},
      blue{COLOR_BLUE},
      cyan{COLOR_CYAN};

public:
    enum action{ left = 'a',right = 'd',up = 'w',down = 's',open = 'e',mark = 'm'};  

public:
    CURSOR(unsigned, unsigned);
    void cursorColor_begin();
    void setCursorPosition(Coords);
    void setCursorWin(window,Coords);
    Coords getCursorPosition();
    void placeCursor(); 
    void eraseCursor(); 
    void move(const int& key);
    void putFlag(); 
    void demine(Coords ij,const int&);  
    
    bool canTouch(Cell); 


};