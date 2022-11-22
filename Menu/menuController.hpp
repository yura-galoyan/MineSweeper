#include "subMenu/options/options.hpp"
#include "MenuController/menuCursor.hpp"
#include "MenuController/menuLoop.hpp"

using keyType = int;

class MENUCONTROLLER
{
private:
    MAINMENU menu;
    OPTIONS optionsMenu;
    MENUCURSOR mainMenuCursor;
    MENUCURSOR optionsCursor;
    MENULOOP menuLoop;
    keyType actionKey;
    struct actions{
        keyType down = 0;
        keyType up = 1;
        keyType enter = 2;
        }action;

public:
    MENUCONTROLLER();
    void startMenu();
    bool play = false;
    bool quit = false;
    void act(keyType);
    keyType getPressedKey();
    keyType chooseAction();
    ~MENUCONTROLLER();
};
