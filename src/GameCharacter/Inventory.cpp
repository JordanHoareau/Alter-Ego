#include "GameCharacter/Inventory.h"
Inventory::~Inventory()
{
    //dtor
}

void Inventory::updateGearItem(GearItem g, int qty){
    m_gearslots[g]+=qty;
}
void Inventory::updateQuestItem(QuestItem q, int qty){
    m_questslots[q]+=qty;
}
void Inventory::updateConsumableItem(ConsumableItem c, int qty){
    m_consumableslots[c]+=qty;
}
void Inventory::updateGold(int g){
    m_gold+=g;
}

void Inventory::unequipGear(GearItem g){
    if( m_gear[g.getGearType()].getGearType() == 0 ) return;
    else{
        m_gear[g.getGearType()] = *(new GearItem());
        GearItem* gear = new GearItem(g);
        updateGearItem(*gear,1);
    }

}
void Inventory::equipGear(GearItem g){
    if( m_gear[g.getGearType()].getGearType() == 0 ){
        GearItem* gear = new GearItem(g);
        m_gear[g.getGearType()] = *gear;
        updateGearItem(g,-1);
    }
    else{
        GearItem* gear = new GearItem(m_gear[g.getGearType()]);
        updateGearItem(*gear,1);
        m_gear[g.getGearType()] = g;
    }
}

void Inventory::print(){}
