#include "../../Library/libraries.hpp"


using Tab = triple;
using states = std::vector<Tab>;
using Matrix = std::vector<states>;
using keyType = int;

const keyType UP   = 'w';
const keyType DOWN = 's';

class MENUCURSOR
{    
private:
    Matrix transactionMatrix;
    bool isInMenu = true;
    COLOR green;  
    Tab currTab,nextTab;

public:
    MENUCURSOR(Matrix);
    
    void moveCursor(Tab&, keyType);
    void highlightCursor(Tab);
    void unHighlightCursor(Tab);
    Tab getNextTab(const Tab, const keyType&);
    Tab getCurrTab();

    ~MENUCURSOR();
};

