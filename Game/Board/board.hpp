#pragma once
#include <ncurses.h>
#include <utility>

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
    void drawGameNameHeader();
    void initScreen();
    void printCenteredText();


    ~BOARD();
};
