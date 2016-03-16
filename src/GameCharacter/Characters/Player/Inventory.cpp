#include "GameCharacter/Characters/Player/Inventory.h"
Inventory::~Inventory()
{
    //dtor
}

void Inventory::updateGearItem(GearItem& g, int qty){
    m_gearslots[g] = m_gearslots[g] + qty;
}
void Inventory::updateQuestItem(Item& q, int qty){
    m_questslots[q]+=qty;
}
void Inventory::updateConsumableItem(ConsumableItem& c, int qty){
    m_consumableslots[c]+=qty;
}
void Inventory::updateGold(int g){
    m_gold+=g;
}

void Inventory::unequipGear(GearItem& g){
    if( m_gear[g.getGearType()].getGearType() == 0 ) return;
    else{
        m_gear[g.getGearType()] = *(new GearItem());
        GearItem* gear = new GearItem(g);
        updateGearItem(*gear,1);
    }

}
void Inventory::equipGear(GearItem& g){
    if( m_gear[g.getGearType()].isEmpty() == true ){
        GearItem* gear = new GearItem(g);
        m_gear[g.getGearType()] = g;
        updateGearItem(g,-1);
    }
    else{
        GearItem* gear = new GearItem(m_gear[g.getGearType()]);
        updateGearItem(*gear,1);
        m_gear[g.getGearType()] = g;
    }
}

void Inventory::print(){

    std::cout <<    "Inventory : " << std::endl <<
                    "Gold : " << m_gold << std::endl <<
                    "GearItem : " << std::endl;

    for(std::map<GearItem,int>::const_iterator i = m_gearslots.begin(); i!=m_gearslots.end(); ++i){
        std::cout << i->second << "x" << i->first.getName() << " " ;
    }
    std::cout << std::endl <<   "QuestItem : " << std::endl;
    for(std::map<Item,int>::const_iterator i = m_questslots.begin(); i!=m_questslots.end(); ++i){
        std::cout << i->second << "x" << i->first.getName() << " " ;
    }
    std::cout << std::endl <<   "ConsumableItem : " << std::endl;
    for(std::map<ConsumableItem,int>::const_iterator i = m_consumableslots.begin(); i!=m_consumableslots.end(); ++i){
        std::cout << i->second << "x" << i->first.getName() << " " ;
    }
    std::cout << std::endl << "Currently equipped : " << std::endl;
    for(int i = 0; i < ItemConstant::GearTypesNumber; i++){
        std::cout << i <<"- " << m_gear[i].getName() << std::endl;
    }

}
