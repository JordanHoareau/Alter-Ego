#include "GameCharacter/Inventory.h"
Inventory::~Inventory()
{
    //dtor
}

void Inventory::addGearItem(GearItem g){
    m_gearslots[g]++;
}
void Inventory::addQuestItem(QuestItem q){
    m_questslots[q]++;
}
void Inventory::addConsumableItem(ConsumableItem c){
    m_consumableslots[c]++;
}
void Inventory::addGold(int g){
    m_gold+=g;
}
void Inventory::equipGear(GearItem g){
}
