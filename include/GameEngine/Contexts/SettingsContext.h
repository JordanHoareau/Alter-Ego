#ifndef SettingsCONTEXT_H
#define SettingsCONTEXT_H

#include "GameContext.h"
#include "MenuContext.h"
#include <iostream>
using namespace std;

class SettingsContext : public MenuContext {

    public:
        void init();
        static SettingsContext* instance() {
            return &m_SettingsContext;
        }

    protected:
    private:
        static SettingsContext m_SettingsContext;
        int m_value;
};

#endif // SettingsCONTEXT_H
