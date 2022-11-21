#pragma once
//#include <ncurses.h>



/*          ALIASES           */

using coords = std::pair<unsigned,unsigned>;

class BOARD{
private:
    coords yx;

public:
    BOARD(coords);
    void startNcurses();
    void createBoard();
    void drawBoardHeader();
    void drawBoardBody();
    void initScreen();
    void printCenteredText();


    ~BOARD();
};
