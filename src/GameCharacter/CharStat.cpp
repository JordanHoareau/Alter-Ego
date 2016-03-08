#include "CharStat.h"

/* ******************************************** */
/*                  CharStats                   */
/* Gather visible values to player              */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

CharStat::CharStat()
{
    m_health = 0;
    m_spell_damage = 0;
    m_weapon_damage = 0;
    m_resistance = 0;
    m_crit_chance = 0;
    m_speed = 0;
}

CharStat::CharStat(int health, int spell_damage, int weapon_damage, int resistance, int crit_chance, int speed)
{
    m_health = health;
    m_spell_damage = spell_damage;
    m_weapon_damage = weapon_damage;
    m_resistance = resistance;
    m_crit_chance = crit_chance;
    m_speed = speed;
}

CharStat::~CharStat()
{

}

void CharStat::setStats(){

}
