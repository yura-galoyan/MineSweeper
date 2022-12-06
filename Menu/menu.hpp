#pragma once
#include "../Library/Types/types.cpp"
#include "../Library/Colors/Colors.hpp"


#include <vector>

const keyType UP   = 'w';
const keyType DOWN = 's';

      using Tab = triple;
      using states = std::vector<Tab>;
      using Matrix = std::vector<states>;
      using keyType = int;

class MENU
{
private:
   
    Matrix transactionMatrix;
    bool isInMenu = true;
    COLOR green = {COLOR_WHITE,-1};  
    Tab currTab,nextTab;

protected:
    struct MENUTABS{
    coord coordY;
    window win;
    const char * name;
    };
    
public:
    MENU(Matrix transactionMatrix);

    Tab getNextTab(const Tab, const keyType&);
    Tab getCurrTab();

    void moveCursor(Tab&, keyType);
    void highlightCursor(Tab);
    void unHighlightCursor(Tab);

    ~MENU();
};

