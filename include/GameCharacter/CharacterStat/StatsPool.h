#ifndef STATSPOOL_H
#define STATSPOOL_H

#include <SFML/Graphics.hpp>

#include "Stats.h"
#include "Strength.h"
#include "Agility.h"
#include "Toughness.h"

#include "StatConstant.h"



class StatsPool
{
    public:
        StatsPool(){}
        virtual ~StatsPool(){delete this;}
        StatsPool(Strength& stg,
                  Agility& agi,
                  Toughness& tgh);

        void initPool(Strength& stg,
                        Agility& agi,
                        Toughness& tgh);
        void updatePool(Strength& stg,
                        Agility& agi,
                        Toughness& tgh);

        Strength getStrength(){return m_pool[StatConstant::StrengthID];}
        Agility getAgility(){return m_pool[StatConstant::AgilityID];}
        Toughness getToughness(){return m_pool[StatConstant::ToughnessID];}
        void test();
        void Free();

        int* getPool(){return m_pool;}

    protected:
        int m_pool[StatConstant::StatsPoolSize];


    private:
};

#endif // STATSPOOL_H
