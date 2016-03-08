#include "Stats.h"

/* ******************************************** */
/*                     Stats                    */
/* Gather used values in combat damage          */
/* calculation with their appropriate methods   */
/*                                              */
/* Parent class : none                          */
/* Children classes : visible stats to player   */
/*                                              */
/* ******************************************** */

Stats::Stats()
{
    m_health = 0;
    m_spell_damage = 0;
    m_weapon_damage = 0;
    m_resistance = 0;
    m_crit_chance = 0;
    m_speed = 0;
}

Stats::Stats(int health, int spell_damage, int weapon_damage, int resistance, int crit_chance, int speed)
{
    m_health = health;
    m_spell_damage = spell_damage;
    m_weapon_damage = weapon_damage;
    m_resistance = resistance;
    m_crit_chance = crit_chance;
    m_speed = speed;
}

Stats::~Stats()
{

}
