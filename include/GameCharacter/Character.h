#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <JSonParser/json-forwards.h>
#include <JSonParser/json.h>

#include "Constants/StatsConstant.h"
#include "Quests/Quest.h"
#include "Items/Item.h"
#include "Attacks/Attack.h"
#include "Attacks/ClassAttack.h"
#include "Attacks/WeaponAttack.h"

#include <vector>
using namespace std;

class Character
{
    public:
        Character();
        Character(sf::String& name, int str, int agi, int tgh, Gender gender, int classID=0, int weaponID=0, int lvl=1);      //      New character
        Character(int saveID);                                                                  //      Character loaded
        void updateStats();
        void updateCaracs(int str, int agi, int tgh);

    protected:
        // Identification attributes
        sf::String m_name;
        Gender m_gender;

        // Battle attributes
        int m_lvl;
        int m_currentHealth;
        int m_caracs[StatsConstant::CaracsNumber];
        int m_stats[StatsConstant::StatsNumber];
        int m_stamina;
        int m_energy;
        int m_classID;
        int m_weaponID;
        vector<Attack> m_attacks;



        // Offbattle attributes
        int m_gold;

};


#endif // CHARACTER_H
