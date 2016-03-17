#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include "SellableItem.h"

class ConsumableItem : public SellableItem {
    public:
        ConsumableItem(int id){
            Json::Value root;
            Json::Reader reader;
            std::ifstream consumableitems_file("data\\Items\\ConsumableItems.json", std::ifstream::binary);
            bool AttackparsingSuccessful = reader.parse( consumableitems_file, root );
            if(AttackparsingSuccessful){
                const Json::Value consumableitems_node = root["consumableitems"];
                for(unsigned int i = 0; i < consumableitems_node.size() ; ++i ){
                    const Json::Value consumableitem_node=consumableitems_node[i];
                    if(consumableitem_node["m_itemID"] == id){
                        m_id = consumableitem_node["m_itemID"].asInt();
                        m_name = consumableitem_node["m_name"].asString();
                        m_description = consumableitem_node["m_description"].asString();
                        m_sellvalue = consumableitem_node["m_sellvalue"].asInt();
                        m_buyvalue = consumableitem_node["m_buyvalue"].asInt();
                        m_healthbonus = consumableitem_node["m_healthbonus"].asInt();
                    }
                }
            }else{return ;}
        }
        int getHealthBonus(){return m_healthbonus;}
    protected:
    private:
        int m_healthbonus;
};

#endif // CONSUMABLEITEM_H
