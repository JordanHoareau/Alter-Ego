#ifndef CHARSTAT_H
#define CHARSTAT_H

#include "Stats.h"
#include "StatsPool.h"
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
        CharStat(int health, int spell_damage, int weapon_damage, int resistance, int crit_chance, int speed);
        virtual ~CharStat();

        // Setting stats method
        virtual void setStats();

    protected:

    private:
        int m_health;
        int m_spell_damage;
        int m_weapon_damage;
        int m_resistance;
        int m_crit_chance;
        int m_speed;
};

#endif // CHARSTAT_H
