#ifndef MoveCONTEXT_H
#define MoveCONTEXT_H

#include "GameContext.h"
#include "PlayContext.h"
#include <iostream>
using namespace std;

class MoveContext : public PlayContext {

    public:
        void init();
        static MoveContext* instance() {
            return &m_MoveContext;
        }

    protected:
    private:
        static MoveContext m_MoveContext;
        int m_value;
};

#endif // MoveCONTEXT_H
