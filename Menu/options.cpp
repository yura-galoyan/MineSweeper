#include "options.hpp"


OPTIONS:: OPTIONS(){
   
//    overAllX = getmaxx(stdscr)/2 - 40;
    initOptionsTabs();
}



void OPTIONS::initOptionsTabs(){
//    initTab(height,getmaxy(stdscr)/5,"Height");
    initTab(width,height.coordY + delta,"Width");
    initTab(mines_count,width.coordY + delta,"Mines Count");
    initTab(back,mines_count.coordY + delta,"Back");
}

void OPTIONS::createOptionMenu(){
    clearScreen();
    drawOptionsHeader();
    //FIXME: must work woth virtual function from menu
    // drawTab(height.win,height.name);
    // drawTab(width.win,width.name);
    // drawTab(mines_count.win,mines_count.name);
    // drawTab(back.win,back.name);
}

void OPTIONS::drawOptionsHeader(){
//       mvprintw(1,62," _____       _    _                \n");
//       mvprintw(2,62,"|     | ___ | |_ |_| ___  ___  ___ \n");
//       mvprintw(3,62,"|  |  || . ||  _|| || . ||   ||_ -|\n");
//       mvprintw(4,62,"|_____||  _||_|  |_||___||_|_||___|\n");
//       mvprintw(5,62,"       |_|                         \n");
}

//FIXME: make all Ncurses WINDOW* an abstraction layer

// WINDOW* OPTIONS::getHeightW(){
//     return height.win;
// };
// 
// WINDOW* OPTIONS::getWidthW(){
//     return width.win;
// }
// 
// WINDOW* OPTIONS::getMinesCountW(){
//     return mines_count.win;
// };
// 
// WINDOW* OPTIONS::getBackW(){
//     return back.win;
// };


OPTIONS::~ OPTIONS(){

}
