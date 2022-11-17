#include "menuCursor.hpp"


MENUCURSOR::MENUCURSOR(Matrix transactionMatrix){
    this->transactionMatrix = transactionMatrix; 
    
}


void MENUCURSOR::moveCursor(Tab& currTab,keyType actionKey){
    unHighlightCursor(currTab);
    Tab nextTab = getNextTab(currTab,actionKey);
    highlightCursor(nextTab);
    currTab = nextTab;
}

Tab MENUCURSOR::getNextTab(const Tab currTab, const keyType &actionKey){
    return transactionMatrix[currTab.second][actionKey];

}

void MENUCURSOR::unHighlightCursor(Tab tab){
    //tab.first
}

void MENUCURSOR::highlightCursor(Tab tab){
    //tab.first
}




MENUCURSOR::~MENUCURSOR(){

}