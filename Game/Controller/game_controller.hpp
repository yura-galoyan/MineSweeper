#include "../Game/game.hpp"

#define cursOFF() curs_set(0)


class GAMECONTROLLER
{
private:
    GAME game;
    int labelPosition = 15;
private:
    bool gameIsActive;
public:
    GAMECONTROLLER(Coords,unsigned);

    void startGame();
    int getPressedKey();
    bool keyIsPressed(const int& key);
    ~GAMECONTROLLER();
};


