#include "../Board/board.hpp"
#include "../Cursor/cursor.hpp"
#include "../Gameloop/gameloop.hpp"

class CONTROLLER
{
private:
    BOARD board;
    CURSOR cursor;
    GAMELOOP gameloop;

public:
    CONTROLLER(maxCoords,unsigned);

    void startGame();
    int getPressedKey();
    ~CONTROLLER();
};


