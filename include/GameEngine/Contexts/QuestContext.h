#ifndef QuestCONTEXT_H
#define QuestCONTEXT_H

#include "GameContext.h"
#include "MenuContext.h"
#include <iostream>
using namespace std;

class QuestContext : public MenuContext {

    public:
        void init();
        static QuestContext* instance() {
            return &m_QuestContext;
        }

    protected:
    private:
        static QuestContext m_QuestContext;
        int m_value;
};

#endif // QuestCONTEXT_H
