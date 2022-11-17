#include "menuLoop.hpp"


MENULOOP::MENULOOP(bool menuProcessOn){
    this->menuProcessOn = menuProcessOn;
}

MENULOOP::operator bool(){
    return menuProcessOn;
}

MENULOOP::~MENULOOP(){

}
