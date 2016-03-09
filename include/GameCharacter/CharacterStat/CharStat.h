#ifndef CHARSTAT_H
#define CHARSTAT_H

#include <iostream>
#include "StatConstant.h"
#include "Stats.h"
#include "StatsPool.h"
#include "Strength.h"
#include "Agility.h"
#include "Toughness.h"
/* ******************************************** */
/*                  CharStats                   */
/* Gather visible values to player              */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

class CharStat
{
    public:
        CharStat();
        CharStat(Strength& str, Agility& agi, Toughness& tgh);
        virtual ~CharStat();

        // Setting stats method
        void updateStats(Strength& str, Agility& agi, Toughness& tgh);

        void initStatPool(Strength str, Agility agi, Toughness tgh);
        const int getHealth(){return m_health;}
        const int getSpellDmg(){return m_spell_damage;}
        const int getWeaponDmg(){return m_weapon_damage;}
        const int getResist(){return m_resistance;}
        const int getCritChance(){return m_crit_chance;}
        const int getSpeed(){return m_speed;}
        void test();
        void print() {
          std::cout <<  "-- Statistiques -- " << std::endl <<
                            "Health : " << getHealth() << std::endl <<
                            "Spell Damage : " << getSpellDmg() << std::endl <<
                            "Weapon Damage : " << getWeaponDmg() << std::endl <<
                            "Resistance : " << getResist() << std::endl <<
                            "Crit Chance : " << getCritChance() << std::endl <<
                            "Speed : " << getSpeed() << std::endl;
        }

    protected:

    private:
        int m_health;
        int m_spell_damage;
        int m_weapon_damage;
        int m_resistance;
        int m_crit_chance;
        int m_speed;
        StatsPool m_pool;
};


#endif // CHARSTAT_H
