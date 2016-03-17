#include "GameCharacter/Characters/Player/Inventory.h"
Inventory::~Inventory()
{
    //dtor
}

void Inventory::updateGearItem(int id, int qty){
    GearItem* g = new GearItem(id);
    std::cout<< g->getID() << " is " << g->isEmpty() << std::endl;
    m_gearslots[*g] += qty;
}
void Inventory::updateQuestItem(int id, int qty){
    Item* q = new Item(id);
    m_questslots[*q]+=qty;
}
void Inventory::updateConsumableItem(int id, int qty){
    ConsumableItem* c = new ConsumableItem(id);
    m_consumableslots[*c]+=qty;
}
void Inventory::updateGold(int g){
    m_gold+=g;
}

void Inventory::unequipGear(int geartype){
    std::cout << m_gear[geartype].getID() << " is " << m_gear[geartype].isEmpty() << std::endl;
    if( m_gear[geartype].isEmpty() == true ) std::cout << "Nothing to unequip" << std::endl;
    else{
        updateGearItem(m_gear[geartype].getID(),1);
        m_gear[geartype] = *(new GearItem(0));
    }

}
void Inventory::equipGear(int id){
    GearItem* g = new GearItem(id);
    if(m_gearslots.count(*g) > 0)
    {
        if( m_gear[g->getGearType()].isEmpty() == true ){
        m_gear[g->getGearType()] = *g;
        updateGearItem(g->getID(),-1);
        }
        else{
            unequipGear(g->getGearType());
            updateGearItem(g->getID(),-1);
            m_gear[g->getGearType()] = *g;
        }
    }else{
        std::cout << "Can't equip" << std::endl;
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
