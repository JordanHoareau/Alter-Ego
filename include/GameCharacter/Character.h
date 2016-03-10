#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameCharacter/Stats/CharStat.h"

enum Gender {girl, boy};

class Character
{
    public:
        Character();

    protected:

    private:
        sf::String m_name;
        int m_lvl;
        CharStat m_stats;
        Gender m_gender;
};


#endif // CHARACTER_H
