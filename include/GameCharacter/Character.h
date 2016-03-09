#ifndef CHARACTER_H
#define CHARACTER_H

#include "CharStat.h"

class Character
{
    public:
        Character();

    protected:

    private:
        sf::String m_name;
        int m_lvl;
        CharStat m_stats;
};

#endif // CHARACTER_H
