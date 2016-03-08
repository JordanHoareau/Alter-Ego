#ifndef STATS_H
#define STATS_H

#include "GameCharacter/Stats.h"

/* ******************************************** */
/*                     Stats                    */
/* Gather used values in combat damage          */
/* calculation with their appropriate methods   */
/*                                              */
/* Parent class : none                          */
/* Children classes : visible stats to player   */
/*                                              */
/* ******************************************** */

class Stats
{
    public:
        Stats();
        virtual ~Stats();

        // Primary calculation methods
        virtual int getHealth() =0;
        virtual int getSpellDamage() =0;    // Damage bonus : class spells
        virtual int getWeaponDamage() =0;   // Damage bonus : weapon spells
        virtual int getResistance() =0;
        virtual int getCritChance() =0;     // Critical Hit Chance (150% base damage)
        virtual int getSpeed() =0;          // Speed

        // Setting stats method
        virtual void setStats();

    protected:

    private:
        int m_Health;
        int m_SpellDamage;                  // Damage bonus : class spells
        int m_WeaponDamage;                 // Damage bonus : weapon spells
        int m_Resistance;
        int m_CritChance;                   // Critical Hit Chance (150% base damage)
        int m_Speed;                        // Speed
};

#endif // STATS_H
