#include "mainMenuModel.hpp"
#include "mainMenuView.hpp"
#include "optionsMenuModel.hpp"
#include "optionsMenuView.hpp"

using keyType = int;
using Coords  = std::pair<unsigned,unsigned>;

constexpr auto incValue = 1;
constexpr auto decValue = -1;

class MENUCONTROLLER
{


private:
    MAINMENUMODEL mainMenuModel;
    MAINMENUVIEW mainMenuView;
    OPTIONSMENUMODEL optionsMenuModel;
    OPTIONSMENUVIEW optionsMenuView;
    keyType actionKey;
    bool menuIsActive;
    keyType getPressedKey();
    struct actions{
        keyType down = 0;
        keyType up = 1;
        keyType enter = 2;
        keyType right = 3;
        keyType left = 4;
        } action;

    enum keys{ DOWN = 's', UP = 'w', LEFT = 'a',RIGHT = 'd',ENTER = 'e'};
public:
    bool playIsPressed = false;
    bool quitIsPressed = false;

public:
    MENUCONTROLLER();

    void startMenu();
    void enterOptionsSubMenu();
    void startGame();
    void endGame();
    Coords getYX();
    unsigned getMC();
    keyType chooseAction();
    void printCenteredText(window,const char*);
    ~MENUCONTROLLER();
};
