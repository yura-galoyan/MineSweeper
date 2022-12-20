#pragma once
#include <ncurses.h>
#include <utility>
#include "../../Library/Colors/Colors.hpp"
using Coords = std::pair<unsigned,unsigned>;
using Coord = unsigned;
using window = WINDOW *;

class GAMEVIEW{
private:
    Coords yx;
    unsigned minesCount;

private:
    int startingX = 5;
    window map;
    COLOR lose{6,COLOR_RED};
    COLOR win{8,COLOR_GREEN};
public:
    GAMEVIEW(Coords,unsigned);
    void setGameView(window);
    void startNcurses();
    void createGameView();
    void drawGameViewHeader();
    void drawGameViewBody();

    void printGameOverHeader(int);
    void printYouWinHeader(int);
    

    void drawGameNameHeader();
    void initScreen();
    void printCenteredText();


    ~GAMEVIEW();
};
