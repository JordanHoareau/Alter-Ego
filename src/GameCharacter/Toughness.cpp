#include "GameCharacter/Toughness.h"

/* ******************************************** */
/*                   Toughness                  */
/* Visible stat to player                       */
/* Improve health and resistance                */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

Toughness::Toughness()
{
    m_value = 0;
}

Toughness::Toughness(int value)
{
    m_value = value;
}

Toughness::~Toughness()
{
    //dtor
}

int Toughness::getHealth()
{
    return 20*m_value;
}
int Toughness::getSpellDamage()
{
    return 0;
}
int Toughness::getWeaponDamage()
{
    return 0;
}

int Toughness::getResistance()
{
    return m_value;
}
int Toughness::getCritChance()
{
    return 0;
}
int Toughness::getSpeed()
{
    return 0;
}
