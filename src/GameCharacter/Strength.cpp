#include "GameCharacter/Strength.h"

/* ******************************************** */
/*                   Strength                   */
/* Visible stat to player                       */
/* Improve damages, health and crit_chance      */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

Strength::Strength()
{
    m_value = 0;
}

Strength::Strength(int value)
{
    m_value = value;
}

Strength::~Strength()
{

}

int Strength::getHealth()
{
    return 10*m_value;
}
int Strength::getSpellDamage()
{
    return 20*m_value;
}
int Strength::getWeaponDamage()
{
    return 20*m_value;
}

int Strength::getResistance()
{
    return 0;
}
int Strength::getCritChance()
{
    return 1*m_value;
}
int Strength::getSpeed()
{
    return 0;
}
