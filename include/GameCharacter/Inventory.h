#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "GameCharacter/Items/GearItem.h"
#include "GameCharacter/Items/ConsumableItem.h"
#include "GameCharacter/Items/QuestItem.h"
#include "Constants/ItemConstant.h"

class Inventory
{
    public:
        Inventory(){}
        Inventory(int gold){
            m_gold = gold;
        }
        virtual ~Inventory();
        void updateGearItem(GearItem g, int qty);
        void updateQuestItem(QuestItem q, int qty);
        void updateConsumableItem(ConsumableItem c, int qty);
        void updateGold(int g);
        void unequipGear(GearItem g);
        void equipGear(GearItem g);

    protected:

    private:
        int m_gold;
        std::map<GearItem, int> m_gearslots;
        std::map<ConsumableItem, int> m_consumableslots;
        std::map<QuestItem, int> m_questslots;
        GearItem m_gear[ItemConstant::GearTypesNumber];
};

#endif // INVENTORY_H
