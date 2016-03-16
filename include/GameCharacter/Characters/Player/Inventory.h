#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include "GameCharacter/Items/GearItem.h"
#include "GameCharacter/Items/ConsumableItem.h"
#include "GameCharacter/Items/QuestItem.h"
#include "Constants/ItemConstant.h"

class Inventory
{
    public:
        Inventory(){
            m_gold = 0;
            for(int i = 0; i < ItemConstant::GearTypesNumber; i++) m_gear[i] = *(new GearItem(0,"","",0,0,-1,0,0,0,0,true));
        }
        Inventory(const Inventory& i){
            m_gold = i.m_gold;
            m_gearslots = i.m_gearslots;
            m_consumableslots = i.m_consumableslots;
            m_questslots = i.m_questslots;
            for(int j = 0; j < ItemConstant::GearTypesNumber; j++) m_gear[j] = i.m_gear[j];
        }
        Inventory(int gold){
            m_gold = gold;
            for(int i = 0; i < ItemConstant::GearTypesNumber; i++) m_gear[i] = *(new GearItem(0,"","",0,0,-1,0,0,0,0,true));
        }
        virtual ~Inventory();
        void updateGearItem(GearItem& g, int qty);
        void updateQuestItem(Item& q, int qty);
        void updateConsumableItem(ConsumableItem& c, int qty);
        void updateGold(int g);
        void unequipGear(GearItem& g);
        void equipGear(GearItem& g);
        void print();

    protected:

    private:
        int m_gold;
        std::map<GearItem, int> m_gearslots;
        std::map<ConsumableItem, int> m_consumableslots;
        std::map<Item, int> m_questslots;
        GearItem m_gear[ItemConstant::GearTypesNumber];
};

#endif // INVENTORY_H
