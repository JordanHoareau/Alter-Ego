#ifndef MenuCONTEXT_H
#define MenuCONTEXT_H

#include "GameContext.h"
#include "PlayContext.h"
#include <iostream>
using namespace std;

class MenuContext : public PlayContext {

    public:
        void init();
        static MenuContext* instance() {
            return &m_MenuContext;
        }

    protected:
    private:
        static MenuContext m_MenuContext;
        int m_value;
};

#endif // MenuCONTEXT_H
