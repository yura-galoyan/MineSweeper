#include "mainmenu.hpp"
#include "options.hpp"

using keyType = int;
using Coords  = std::pair<unsigned,unsigned>;

constexpr auto incValue = 1;
constexpr auto decValue = -1;

class Presenter
{


private:
    MAINMENU mainMenu;
    OPTIONS optionsMenu;
private:
    keyType actionKey;
    bool menuActive;

private:
    keyType getPressedKey();

private:
    struct actions{
        keyType down = 0;
        keyType up = 1;
        keyType enter = 2;
        keyType right = 3;
        keyType left = 4;
        } action;


public:
    Coords getYX();
    unsigned getMC();
    Coords yx;

public:
    Presenter();

    void startMenu();
    void enterOptionsSubMenu();
    void startGame();
    void endGame();
    bool play = false;
    bool quit = false;
    
    void act(keyType);
    keyType chooseAction();
    void printCenteredText(window,const char*);
    ~Presenter();
};
