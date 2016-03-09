#ifndef IntroContext_H
#define IntroContext_H

#include "GameContext.h"
#include <iostream>
using namespace std;

class IntroContext : public GameContext {

    public:
        void init();
        static IntroContext* instance() {
            return &m_IntroContext;
        }

    protected:
    private:
        static IntroContext m_IntroContext;
        int m_value;
};

#endif // IntroContext_H
