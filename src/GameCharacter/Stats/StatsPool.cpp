#include "GameCharacter/Stats/StatsPool.h"

StatsPool::StatsPool(Strength& stg, Agility& agi, Toughness& tgh){
    m_pool[StatConstant::StrengthID] = stg.getValue();
    m_pool[StatConstant::AgilityID] = agi.getValue();
    m_pool[StatConstant::ToughnessID] = tgh.getValue();
}

void StatsPool::initPool(Strength& stg, Agility& agi, Toughness& tgh){
    m_pool[StatConstant::StrengthID] = stg.getValue();
    m_pool[StatConstant::AgilityID] = agi.getValue();
    m_pool[StatConstant::ToughnessID] = tgh.getValue();
}

void StatsPool::updatePool(Strength& str, Agility& agi, Toughness& tgh){
    m_pool[StatConstant::StrengthID] += str.getValue();
    m_pool[StatConstant::AgilityID] += agi.getValue();
    m_pool[StatConstant::ToughnessID] += tgh.getValue();
}

void StatsPool::Free(){
    delete this;
}




