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

COLOR white{5,COLOR_WHITE},
      red{6,COLOR_RED},
      yellow{7,COLOR_YELLOW},
      green{8,COLOR_GREEN},
      magenta{9,COLOR_MAGENTA},
      blue{10,COLOR_BLUE},
      cyan{11,COLOR_CYAN};

public:
    enum action{ left = 'a',right = 'd',up = 'w',down = 's',open = 'e',mark = 'q'};  

public: 
    CURSOR(unsigned, unsigned);
    void cursorColor_begin();
    void setCursorPosition(Coords);
    void initCursorForWin(window,Coords);
    Coords getCursorPosition();
    void placeCursor(); 
    void eraseCursor(); 

    void moveTo(const int& key);
    void demine(Coords ij,const int&);  
    void putFlag(bool);

    void printColoredValue(const Coords ij, const int &v, COLOR&);
    void printColoredString(const Coords ij, const char*, COLOR&);
    
    bool canTouch(Cell); 


};