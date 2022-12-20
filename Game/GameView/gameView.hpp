#pragma once
#include <ncurses.h>
#include <utility>

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
