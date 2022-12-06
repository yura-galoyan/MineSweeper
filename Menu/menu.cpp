#include "menu.hpp"

MENU::MENU(Matrix transactionMatrix)
    :transactionMatrix(transactionMatrix ), green(COLOR_GREEN,-1 ), currTab{transactionMatrix[0][1]} 
{

}

void MENU::moveCursor(Tab& tab,keyType actionKey){
    unHighlightCursor(tab);
    Tab nextTab = getNextTab(tab,actionKey);
    highlightCursor(nextTab);
    currTab = nextTab;
}

void MENU::highlightCursor(const Tab tab){
    green.startColor(tab.win);
    drawTab(tab.win,tab.name);
    
}

Tab MENU::getCurrTab(){
    return currTab;
}

Tab MENU::getNextTab(const Tab currTab, const keyType &actionKey){
    return transactionMatrix[currTab.second][actionKey];

}


void MENU::unHighlightCursor(Tab tab){
    green.endColor(tab.win); 
    drawTab(tab.win,tab.name);
}
