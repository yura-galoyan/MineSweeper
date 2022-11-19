#include "menuCursor.hpp"


MENUCURSOR::MENUCURSOR(Matrix transactionMatrix)
    :transactionMatrix(transactionMatrix ), green(COLOR_GREEN,-1 ), currTab{transactionMatrix[0][1]} 
{

}


void MENUCURSOR::moveCursor(Tab& tab,keyType actionKey){
    unHighlightCursor(tab);
    Tab nextTab = getNextTab(tab,actionKey);
    highlightCursor(nextTab);
    currTab = nextTab;
}
Tab MENUCURSOR::getCurrTab(){
    return currTab;
}

Tab MENUCURSOR::getNextTab(const Tab currTab, const keyType &actionKey){
    return transactionMatrix[currTab.second][actionKey];

}

void MENUCURSOR::unHighlightCursor(Tab tab){
    green.endColor(tab.first); 
    DRAW::drawTab(tab.first,tab.third);
}

void MENUCURSOR::highlightCursor(const Tab tab){
    green.startColor(tab.first);
    DRAW::drawTab(tab.first,tab.third);
    
}




MENUCURSOR::~MENUCURSOR(){

}