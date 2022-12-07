#include "Colors.hpp"



    COLOR::COLOR(colorType font,colorType background){
        start_color();
        init_pair(colorGreen,font,background);
        init_pair(colorDefault,COLOR_WHITE,COLOR_BLACK);
    }

    void COLOR::startColor(WINDOW * tab){
        wattroff(tab,COLOR_PAIR(colorDefault));
        wattron(tab,COLOR_PAIR(colorGreen));
    }

    void COLOR::endColor(WINDOW * tab){
        wattroff(tab,COLOR_PAIR(colorGreen));
        wrefresh(tab);
        wattron(tab,COLOR_PAIR(colorDefault));



    }

    COLOR::~COLOR(){
        
    };