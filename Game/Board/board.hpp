#pragma once
#include <utility>  // std::pair
#include <ncurses.h>
#include "../../Library/libraries.hpp"



/*          ALIASES           */

using maxCoords = std::pair<unsigned,unsigned>;

class BOARD{
private:
    maxCoords yx;

public:
    BOARD(maxCoords);
    void startNcurses();
    void createBoard();



    ~BOARD();
};
