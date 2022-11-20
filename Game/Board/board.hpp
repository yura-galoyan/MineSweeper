#pragma once
#include <utility>  // std::pair
#include <ncurses.h>
#include "../../Library/libraries.hpp"



/*          ALIASES           */

using coords = std::pair<unsigned,unsigned>;

class BOARD{
private:
    coords yx;

public:
    BOARD(coords);
    void startNcurses();
    void createBoard();



    ~BOARD();
};
