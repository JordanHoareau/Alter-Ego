#include "StatsPool.h"

StatsPool::StatsPool(Strength& stg, Agility& agi, Toughness& tgh){
    setPool(stg,agi,tgh);
}
void StatsPool::setPool(Strength str, Agility agi, Toughness tgh){
    m_pool =  {     {"Strength",str},
                    {"Agility",agi},
                    {"Toughness",tgh}};
}

std::unordered_map<std::string,Stats&> StatsPool::getPool(){
    return m_pool;
}


