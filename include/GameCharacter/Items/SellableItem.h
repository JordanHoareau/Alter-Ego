#ifndef SELLABLEITEM_H
#define SELLABLEITEM_H

#include "GameCharacter/Items/Item.h"

class SellableItem : public Item
{
    public:
        SellableItem(){}
        SellableItem(const SellableItem& s)
            :   Item(s){
            m_sellvalue = s.m_sellvalue;
            m_buyvalue = s.m_buyvalue;
        }
        SellableItem(int id){
            Json::Value root;
            Json::Reader reader;
            std::ifstream sellableitems_file("data\\Items\\SellableItems.json", std::ifstream::binary);
            bool AttackparsingSuccessful = reader.parse( sellableitems_file, root );
            if(AttackparsingSuccessful){
                const Json::Value sellableitems_node = root["sellableitems"];
                for(unsigned int i = 0; i < sellableitems_node.size() ; ++i ){
                    const Json::Value sellableitem_node=sellableitems_node[i];
                    if(sellableitem_node["m_itemID"] == id){
                        m_id = sellableitem_node["m_sellableitemID"].asInt();
                        m_name = sellableitem_node["m_name"].asString();
                        m_description = sellableitem_node["m_description"].asString();
                        m_sellvalue = sellableitem_node["m_sellvalue"].asInt();
                        m_buyvalue = sellableitem_node["m_buyvalue"].asInt();
                    }
                }
            }else{return ;}
        }
        int getSellValue(){return m_sellvalue;}
        int getBuyValue(){return m_buyvalue;}
        virtual ~SellableItem();

    protected:
        int m_sellvalue;
        int m_buyvalue;

    private:
};

#endif // SELLABLEITEM_H
