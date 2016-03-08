#ifndef AGILITY_H
#define AGILITY_H

#include "GameCharacter/Stats.h"
/* ******************************************** */
/*                   Agility                    */
/* Visible stat to player                       */
/* Improve damages, speed and crit_chance       */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

class Agility: public Stats
{
    public:
        Agility();
        Agility(int value);
        virtual ~Agility();

        virtual int getHealth();
        virtual int getSpellDamage();    // Damage bonus : class spells
        virtual int getWeaponDamage();   // Damage bonus : weapon spells
        virtual int getResistance();
        virtual int getCritChance() =0;     // Critical Hit Chance (150% base damage)
        virtual int getSpeed() =0;          // Speed

    protected:

    private:
        int m_value;
};

#endif // AGILITY_H
