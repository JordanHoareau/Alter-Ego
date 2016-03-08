#include "StatsPool.h"

void StatsPool::setPool(Strength str, Agility agi, Toughness tgh){
    m_pool =  {     {"Strength",str},
                    {"Agility",agi},
                    {"Toughness",tgh}};
}

std::unordered_map<std::string,Stats&> StatsPool::getPool(){
    return m_pool;
}
