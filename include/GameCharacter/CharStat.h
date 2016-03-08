#ifndef CHARSTAT_H
#define CHARSTAT_H

#include "Constants.h"
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
        CharStat(Strength str, Agility agi, Toughness tgh);
        virtual ~CharStat();

        // Setting stats method
        virtual void setStats();

        void initStatPool(Strength str, Agility agi, Toughness tgh);
        int getHealth(){return m_health;}
        int getSpellDmg(){return m_spell_damage;}
        int getWeaponDmg(){return m_weapon_damage;}
        int getResist(){return m_resistance;}
        int getCritChance(){return m_crit_chance;}
        int getSpeed(){return m_speed;}
       // void test();

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
