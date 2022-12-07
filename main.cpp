#include "Menu/Presenter.hpp"
#include "Game/Controller/controller.hpp"

//FIXME: try changin everything in code independent from Ncurses, as much as possible
//TODO: FIND A WAY TO GET RID OF WINDOW*, MAKE ANOTHER CLASS THAT ALSO WORKS LIKE POINTER WITH unique_pointer PROBABLY
int main(){
    Presenter presenter;
    presenter.startMenu();
        if(presenter.quit){  
        endwin();
        
    }
   else if(presenter.play){
        CONTROLLER controller;
        controller.startGame();
    }


}