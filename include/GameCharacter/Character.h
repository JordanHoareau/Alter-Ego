#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Constants/StatsConstant.h"
#include "Quests/Quest.h"
#include "Items/Item.h"
#include "Attacks/Attack.h"

#include <vector>
using namespace std;

class Character
{
    public:
        Character();
        Character(sf::String name, int str, int agi, int tgh, Gender gender, int classID);   //      New character
        Character(int saveID);                                                  //      Character Loading
        void updateStats();
        void updateCaracs(int str, int agi, int tgh);

    protected:
        sf::String m_name;
        Gender m_gender;
        int m_lvl;
        int m_currentHealth;
        int m_gold;
        int m_caracs[StatsConstant::CaracsNumber];
        int m_stats[StatsConstant::StatsNumber];
        vector<Quest> m_quests;
        vector<Item> m_items;
        vector<Attack> m_attacks;
};


#endif // CHARACTER_H
