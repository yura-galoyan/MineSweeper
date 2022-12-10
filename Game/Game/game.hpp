#include <ncurses.h>
#include <utility>

using maxCoords = std::pair<unsigned,unsigned>; 

class GAME{

private:
    unsigned height,
             width,
             minesCount;
    Matrix matrix;


public:
    GAME(maxCoords,unsigned);



    ~GAME();
};
