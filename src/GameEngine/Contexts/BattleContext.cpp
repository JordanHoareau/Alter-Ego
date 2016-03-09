#include "BattleContext.h"

BattleContext BattleContext::m_BattleContext;

void BattleContext::init(){
    cout << "       BattleContext - Init" << endl;
    m_value = 2;
}
