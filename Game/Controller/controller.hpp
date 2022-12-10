#include "../Board/board.hpp"
#include "../Cursor/cursor.hpp"

class CONTROLLER
{
private:
    BOARD board;
    CURSOR cursor;

private:
    bool gameActive;
public:
    CONTROLLER(maxCoords,unsigned);

    void startGame();
    int getPressedKey();
    ~CONTROLLER();
};


