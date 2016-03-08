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
    m_ChildrenSize = 0;
}

CharStat::CharStat(int children_size)
{
    m_ChildrenSize = children_size;
}

CharStat::~CharStat()
{

}

CharStat::setStats(){
    m_children[0] = new(Strength(1));
   // m_children[1] = new(Agility(0));
    m_children[2] = new(Strength(0));

    for(int i = 0; i < m_ChildrenSize; i++){
        m_Health = m_Health + m_children.getHealth();
        m_SpellDamage = m_SpellDamage + m_children.getSpellDamage();
        m_WeaponDamage = m_WeaponDamage + m_children.getWeaponDamage();
        m_Resistance = m_Resistance + m_children.getResistance();
        m_CritChance = m_CritChance + m_children.getCritChance();
        m_Speed = m_Speed + m_children.getSpeed();
    }
    cout << "Health : " << m_Health << endl <<
            "SpellDamage : " << m_SpellDamage << endl <<
            "WeaponDamage : " << m_WeaponDamage << endl <<
            "Resistance : " << m_Resistance << endl <<
            "CritChance : " << m_CritChance << endl <<
            "Speed : " << m_Speed << endl;
}
