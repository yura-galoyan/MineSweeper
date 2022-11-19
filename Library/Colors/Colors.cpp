#include "Colors.hpp"



    COLOR::COLOR(colorType font,colorType background){
        start_color();
        init_pair(color,font,background);
    }

    void COLOR::startColor(WINDOW * tab){
        wattron(tab,COLOR_PAIR(color));
    }

    void COLOR::endColor(WINDOW * tab){
        wattroff(tab,COLOR_PAIR(color));
        wrefresh(tab);
    }

    COLOR::~COLOR(){
        
    };