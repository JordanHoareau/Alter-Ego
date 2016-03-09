#include "GameCharacter/CharacterStat/CharStat.h"

#include <iostream>
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
}
CharStat::~CharStat()
{
    m_pool.Free();
    delete this;
}


CharStat::CharStat(Strength& str, Agility& agi, Toughness& tgh)
{
    m_health =  str.getValue()*StatConstant::StrengthHealthRatio
             +  tgh.getValue()*StatConstant::ToughnessHealthRatio
             +  agi.getValue()*StatConstant::AgilityHealthRatio;

    m_spell_damage =  str.getValue()*StatConstant::StrengthSpellDmgRatio
                   +  tgh.getValue()*StatConstant::ToughnessSpellDmgRatio
                   +  agi.getValue()*StatConstant::AgilitySpellDmgRatio;

    m_weapon_damage =  str.getValue()*StatConstant::StrengthWeaponDmgRatio
                    +  tgh.getValue()*StatConstant::ToughnessWeaponDmgRatio
                    +  agi.getValue()*StatConstant::AgilityWeaponDmgRatio;

    m_resistance =  str.getValue()*StatConstant::StrengthResistanceRatio
                 +  tgh.getValue()*StatConstant::ToughnessResistanceRatio
                 +  agi.getValue()*StatConstant::AgilityResistanceRatio;

    m_crit_chance = str.getValue()*StatConstant::StrengthCritChanceRatio
                  + tgh.getValue()*StatConstant::ToughnessCritChanceRatio
                  + agi.getValue()*StatConstant::AgilityCritChanceRatio;

    m_speed =       str.getValue()*StatConstant::StrengthSpeedRatio
                 +  tgh.getValue()*StatConstant::ToughnessSpeedRatio
                 +  agi.getValue()*StatConstant::AgilitySpeedRatio;

    m_pool.initPool(str, agi, tgh);
}

void CharStat::updateStats(Strength& str, Agility& agi, Toughness& tgh){
    m_pool.updatePool(str,agi,tgh);
    int *tmp;
    tmp = m_pool.getPool();
    m_health =  tmp[StatConstant::StrengthID]*StatConstant::StrengthHealthRatio
             +  tmp[StatConstant::ToughnessID]*StatConstant::ToughnessHealthRatio
             +  tmp[StatConstant::AgilityID]*StatConstant::AgilityHealthRatio;

    m_spell_damage =  tmp[StatConstant::StrengthID]*StatConstant::StrengthSpellDmgRatio
                   +  tmp[StatConstant::ToughnessID]*StatConstant::ToughnessSpellDmgRatio
                   +  tmp[StatConstant::AgilityID]*StatConstant::AgilitySpellDmgRatio;

    m_weapon_damage =  tmp[StatConstant::StrengthID]*StatConstant::StrengthWeaponDmgRatio
                    +  tmp[StatConstant::ToughnessID]*StatConstant::ToughnessWeaponDmgRatio
                    +  tmp[StatConstant::AgilityID]*StatConstant::AgilityWeaponDmgRatio;

    m_resistance =  tmp[StatConstant::StrengthID]*StatConstant::StrengthResistanceRatio
                 +  tmp[StatConstant::ToughnessID]*StatConstant::ToughnessResistanceRatio
                 +  tmp[StatConstant::AgilityID]*StatConstant::AgilityResistanceRatio;

    m_crit_chance = tmp[StatConstant::StrengthID]*StatConstant::StrengthCritChanceRatio
                  + tmp[StatConstant::ToughnessID]*StatConstant::ToughnessCritChanceRatio
                  + tmp[StatConstant::AgilityID]*StatConstant::AgilityCritChanceRatio;

    m_speed =       tmp[StatConstant::StrengthID]*StatConstant::StrengthSpeedRatio
                 +  tmp[StatConstant::ToughnessID]*StatConstant::ToughnessSpeedRatio
                 +  tmp[StatConstant::AgilityID]*StatConstant::AgilitySpeedRatio;
}

void CharStat::test(){
    Strength* s = new Strength(1);
    Agility* ag = new Agility(1);
    Toughness* tg = new Toughness(1);
    CharStat* cp = new CharStat(*s,*ag,*tg);
    cp->print();
    cp->updateStats(*s,*ag,*tg);
    cp->print();
}


