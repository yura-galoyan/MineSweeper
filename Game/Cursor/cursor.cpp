#include "cursor.hpp"



CURSOR::CURSOR(unsigned maxy,unsigned maxx)
{
    this->maxx = maxx;
    this->maxy = maxy;
};

void CURSOR::cursorColor_begin(){
    start_color();
    use_default_colors();
    init_pair(CURS_COLOR,COLOR_GREEN,-1);
    wattron(map,COLOR_PAIR(CURS_COLOR));
};

void CURSOR::setCursorPosition(Coords ij){
    i = ij.first;
    j = ij.second;
}

void CURSOR::setCursorWin(window w,Coords ij){
    map = w;
    i = ij.first;
    j = ij.second;
}

Coords CURSOR::getCursorPosition(){
    return {i,j};
}
void CURSOR::placeCursor(){
    cursorColor_begin();
    mvwprintw(map,i, 2*j - 1, "[");
    mvwprintw(map,i, 2*j + 1, "]");
    wrefresh(map);
}

void CURSOR::eraseCursor(){
    mvwprintw(map,i, 2*j - 1, " ");
    mvwprintw(map,i, 2*j + 1, " ");
    wrefresh(map);
}


void CURSOR::move(const int& key){
    switch(key){
    case CURSOR::left:
        eraseCursor();
            j = (j - 1) < 1 ? j - 1 + maxx : (j - 1) % maxx  ; 
        placeCursor();
        break;
    case CURSOR::right:
        eraseCursor();
            j = (j)%(maxx) + 1;
        placeCursor();
        break;
    case CURSOR::up:
        eraseCursor();
            i = (i - 1) < 1 ? (i - 1 + maxy) : (i - 1) % maxy;
        placeCursor();
        break;
    case CURSOR::down:
        eraseCursor();
            i = (i)%(maxy) + 1;
        placeCursor();
        break;
    }    
};


bool CURSOR::canTouch(Cell C){
    return !C.state;   
}


// plamaxyer puts flag,to remember that there might be a bomb
void CURSOR::putFlag(){

};

void CURSOR::demine(Coords ij,const int& v){
    if(v == 0 )
    mvwprintw(map,ij.first,ij.second * 2," ");
    else if(v == 9)
    mvwprintw(map,ij.first,ij.second * 2,"*");
    else
    mvwprintw(map,ij.first,ij.second * 2,"%d",v);
    
    wrefresh(map);
};  

