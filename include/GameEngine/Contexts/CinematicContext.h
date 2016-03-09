#ifndef CinematicCONTEXT_H
#define CinematicCONTEXT_H

#include "GameContext.h"
#include <iostream>
using namespace std;

class CinematicContext : public GameContext {

    public:
        void init();
        static CinematicContext* instance() {
            return &m_CinematicContext;
        }

    protected:
    private:
        static CinematicContext m_CinematicContext;
        int m_value;
};

#endif // CinematicCONTEXT_H
