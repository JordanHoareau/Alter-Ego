#include "GameEngine/Contexts/MenuContext.h"

MenuContext MenuContext::m_MenuContext;

void MenuContext::init(){
    cout << "       MenuContext - Init" << endl;
    m_value = 2;
}
