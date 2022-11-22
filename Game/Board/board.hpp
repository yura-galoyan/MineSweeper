#pragma once
//#include <ncurses.h>



/*          ALIASES           */

using maxCoords = std::pair<unsigned,unsigned>;

class BOARD{
private:
    maxCoords yx;

public:
    BOARD(maxCoords);
    void startNcurses();
    void createBoard();
    void drawBoardHeader();
    void drawBoardBody();
    void initScreen();
    void printCenteredText();


    ~BOARD();
};
