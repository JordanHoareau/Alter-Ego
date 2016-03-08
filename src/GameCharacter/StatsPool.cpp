#include "StatsPool.h"

void StatsPool::setPool(Strength stg, Agility agi, Toughness tgh){
    pool =  {   {"Strength",stg},
                {"Agility",agi},
                {"Toughness",tgh}};
}
