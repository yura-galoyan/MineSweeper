#include <iostream>
#include "cursor.hpp"
#include <ncurses.h>
enum direction{ left = 'a',right = 'd',up = 'w',down = 's',open = 'o',mark = 'm'} dir;  


CURSOR::CURSOR(unsigned maxy,unsigned maxx){
    this->maxx = maxx;
    this->maxy = maxy;
};

void CURSOR::cursorColor_begin(){
    start_color();
    use_default_colors();
    init_pair(CURS_COLOR,COLOR_GREEN,-1);
    attron(COLOR_PAIR(CURS_COLOR));
};

void CURSOR::cursorColor_end(){
    attroff(COLOR_PAIR(CURS_COLOR));
    refresh();
}

int MAP::sum(Matrix mat){
    int sum = 0;
    for(int i = 0;i<y;++i)
        for(int j = 0;j<x;++j)
    sum += mat[i][j].first;
    return sum;
}

void CURSOR::placeCursor(){
    noecho();
    cursOFF(); 
    cursorColor_begin();
    mvprintw(i + 10, 2*j + 6,"[");
    mvprintw(i + 10, 2*j + 8,"]");
    cursorColor_end();
}

void CURSOR::eraseCursor(){
    mvprintw(i + 10,2*j + 6," ");
    mvprintw(i + 10,2*j + 8," ");
}


// for any pressed key
void CURSOR::interact(const int& key){
         if( key == left )
         move(left);
    else if( key == right )
         move(right);
    else if( key == up )
         move(up);
    else if( key == down )
         move(down);
    
    if(canTouch()){
        switch(key){
        case open:
             demine();
        case mark:
             putFlag(); 
        }
    }

    mvprintw(1,1,"%3d  %3d",i + 1,j + 1);
};

void CURSOR::move(const int& key){
    switch(key){
    case left:
        eraseCursor();
            j = (j - 1) < 0 ? j - 1 + maxx : (j - 1) % maxx  ;
            
        placeCursor();
        break;
    case right:
        eraseCursor();
            j = (j + 1)%maxx;
        placeCursor();
        break;
    case up:
        eraseCursor();
            i = (i - 1) < 0 ? (i - 1 + maxy) : (i - 1) % maxy;
        placeCursor();
        break;
    case down:
        eraseCursor();
            i = (i + 1)%maxy;
        placeCursor();
        break;
    }    
};


bool CURSOR::canTouch(){
    return false;   
}


// plamaxyer puts flag,to remember that there might be a bomb
void CURSOR::putFlag(){

};

// plamaxyer tries to demine a bomb
void CURSOR::demine(){

};  

