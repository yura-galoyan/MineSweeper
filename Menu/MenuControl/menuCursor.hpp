#include <vector>
#include "ncurses.h"
#include "map"

using Tab = std::pair<WINDOW*,int>;
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

public:
    MENUCURSOR(Matrix);

    void moveCursor(Tab&, keyType);
    void highlightCursor(Tab);
    void unHighlightCursor(Tab);
    Tab getNextTab(const Tab, const keyType&);


    ~MENUCURSOR();
};

