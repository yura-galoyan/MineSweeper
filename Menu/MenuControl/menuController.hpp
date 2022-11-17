#include "../menu.hpp"
#include "menuCursor.hpp"
#include "menuLoop.hpp"

using keyType = int;

class MENUCONTROLLER
{
private:
    MENU menu;
    MENUCURSOR menuCursor;
    MENULOOP menuLoop;
    keyType actionKey;
    Tab currTab,nextTab;
    struct direction{
        keyType down = 0;
        keyType up = 1;
        }dir;

public:
    MENUCONTROLLER();
    void startMenu();

    void act(keyType);
    keyType getPressedKey();
    keyType chooseAction();
    ~MENUCONTROLLER();
};
