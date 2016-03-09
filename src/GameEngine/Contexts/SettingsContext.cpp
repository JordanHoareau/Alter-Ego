#include "GameEngine/Contexts/SettingsContext.h"

SettingsContext SettingsContext::m_SettingsContext;

void SettingsContext::init(){
    cout << "       SettingsContext - Init" << endl;
    m_value = 2;
}
