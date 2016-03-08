#ifndef STATSPOOL_H
#define STATSPOOL_H

#include "Stats.h"
#include "Strength.h"
#include "Agility.h"
#include "Toughness.h"
#include <unordered_map>

class StatsPool
{
    public:
        void setPool(Strength stg,
                     Agility agi,
                     Toughness tgh);

        std::unordered_map<std::string,Stats&> getPool();
    protected:
        std::unordered_map<std::string,Stats&> m_pool;
    private:
};

#endif // STATSPOOL_H
