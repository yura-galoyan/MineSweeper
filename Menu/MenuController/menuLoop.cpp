#include "menuLoop.hpp"


MENULOOP::MENULOOP(bool menuProcessOn):menuProcessOn(menuProcessOn)
{

}

MENULOOP::operator bool(){
    return menuProcessOn;
}

MENULOOP::~MENULOOP(){

}
