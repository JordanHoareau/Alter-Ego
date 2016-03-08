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

class CharStat: public Stats
{
    public:
        CharStat();
        CharStat(Strength str, Agility agi, Toughness tgh);
        virtual ~CharStat();

        // Setting stats method
        virtual void setStats();

        void initStatPool(Strength str, Agility agi, Toughness tgh);

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
