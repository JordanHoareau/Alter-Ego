#include "Agility.h"

/* ******************************************** */
/*                   Agility                    */
/* Visible stat to player                       */
/* Improve damages, speed and crit_chance       */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

Agility::Agility()
{
    m_value = 0;
}

Agility::Agility(int value)
{
    m_value = value;
}

Agility::~Agility()
{
    //dtor
}

int Agility::getHealth()
{
    return 0;
}
int Agility::getSpellDamage()
{
    return 20*m_value;
}
int Agility::getWeaponDamage()
{
    return 20*m_value;
}

int Agility::getResistance()
{
    return 0;
}
int Agility::getCritChance()
{
    return 1*m_value;
}
int Agility::getSpeed()
{
    return 10*m_value;
}
