#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H

#include "GameContext.h"
#include <iostream>
using namespace std;

class PlayContext : public GameContext {

    public:
        void init();
        static PlayContext* instance() {
            return &m_PlayContext;
        }

    protected:
    private:
        static PlayContext m_PlayContext;
        int m_value;
        int m_test;
};

#endif // PLAYCONTEXT_H
