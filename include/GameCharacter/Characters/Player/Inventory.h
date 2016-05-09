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
            for(int i = 0; i < ItemConstant::GearTypesNumber; i++) m_gear[i] = *(new GearItem(0));
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
            for(int i = 0; i < ItemConstant::GearTypesNumber; i++) m_gear[i] = *(new GearItem(0));
        }
        virtual ~Inventory();
        void updateGearItem(int id, int qty);
        void updateQuestItem(int id, int qty);
        void updateConsumableItem(int id, int qty);
        void updateGold(int g);
        void unequipGear(int geartype);
        void equipGear(int id);
        void setGear(int id);
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
