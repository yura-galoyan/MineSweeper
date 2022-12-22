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

void CURSOR::initCursor(const window& w,Coords ij){
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

void CURSOR::moveTo(const int& key){
    switch(key){
    case CURSOR::LEFT:
        eraseCursor();
            j = (j - 1) < 1 ? j - 1 + maxx : (j - 1) % maxx  ; 
        placeCursor();
        break;
    case CURSOR::RIGHT:
        eraseCursor();
            j = (j)%(maxx) + 1;
        placeCursor();
        break;
    case CURSOR::UP:
        eraseCursor();
            i = (i - 1) < 1 ? (i - 1 + maxy) : (i - 1) % maxy;
        placeCursor();
        break;
    case CURSOR::DOWN:
        eraseCursor();
            i = (i)%(maxy) + 1;
        placeCursor();
        break;
    }    
};

void CURSOR::mark(){
    printColoredString({i,j},"#",red);
};

void CURSOR::unMark(){
    printColoredString({i,j},"#",white);
}

void CURSOR::printColoredValue(const Coords ij,const int &v,COLOR c){
    c.startColor(map);
    mvwprintw(map,ij.first,ij.second*2,"%d",v);
    c.endColor(map);
};

void CURSOR::printColoredString(const Coords ij,const char* ch,COLOR c){
    c.startColor(map);
    mvwprintw(map,ij.first,ij.second*2,"%s",ch);
    c.endColor(map);
}

void CURSOR::demine(Coords ij,const int& v){
    switch(v){
    case 0:    
        printColoredString(ij," ",white);
        break;
    case 9:
        printColoredString(ij,"*",red);
        break;
    case 1:
        printColoredValue(ij,v,white);
        break;
    case 2:
        printColoredValue(ij,v,green);
        break;
    case 3:
        printColoredValue(ij,v,cyan);
        break;
    case 4:
        printColoredValue(ij,v,blue);
        break;
    case 5:
        printColoredValue(ij,v,magenta);
        break;
    case 6:
        printColoredValue(ij,v,yellow);
        break;
    case 7:
        printColoredValue(ij,v,red);
        break;
    default:
        printColoredValue(ij,v,white);
        break;
}
    wrefresh(map);
};  

