#ifndef BattleCONTEXT_H
#define BattleCONTEXT_H

#include "GameContext.h"
#include "PlayContext.h"
#include <iostream>
using namespace std;

class BattleContext : public PlayContext {

    public:
        void init();
        static BattleContext* instance() {
            return &m_BattleContext;
        }

    protected:
    private:
        static BattleContext m_BattleContext;
        int m_value;
};

#endif // BattleCONTEXT_H
