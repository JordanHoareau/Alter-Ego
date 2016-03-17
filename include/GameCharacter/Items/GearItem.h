#ifndef GEARITEM_H
#define GEARITEM_H

#include "GameCharacter/Items/SellableItem.h"

#include <iostream>

class GearItem : public SellableItem
{
    public:
        GearItem(){}
        GearItem(const GearItem& g)
            :   SellableItem(g){
            m_geartype = g.m_geartype;
            m_unlocklvl = g.m_unlocklvl;
            m_strbonus = g.m_strbonus;
            m_agibonus = g.m_agibonus;
            m_tghbonus = g.m_tghbonus;
        }
        GearItem(int id){
            Json::Value root;
            Json::Reader reader;
            std::ifstream gearitems_file("data\\Items\\GearItems.json", std::ifstream::binary);
            bool AttackparsingSuccessful = reader.parse( gearitems_file, root );
            if(AttackparsingSuccessful){
                const Json::Value gearitems_node = root["gearitems"];
                for(unsigned int i = 0; i < gearitems_node.size() ; ++i ){
                    const Json::Value gearitem_node=gearitems_node[i];
                    if(gearitem_node["m_itemID"] == id){
                        m_id = gearitem_node["m_itemID"].asInt();
                        m_name = gearitem_node["m_name"].asString();
                        m_description = gearitem_node["m_description"].asString();
                        m_sellvalue = gearitem_node["m_sellvalue"].asInt();
                        m_buyvalue = gearitem_node["m_buyvalue"].asInt();
                        m_geartype = gearitem_node["m_geartype"].asInt();
                        m_unlocklvl = gearitem_node["m_unlocklvl"].asInt();
                        m_strbonus = gearitem_node["m_strbonus"].asInt();
                        m_agibonus = gearitem_node["m_agibonus"].asInt();
                        m_tghbonus = gearitem_node["m_tghbonus"].asInt();
                    }
                }
            }else{return ;}
        }
        virtual ~GearItem();
        int getGearType(){return m_geartype;}
        int getUnlockLvl(){return m_unlocklvl;}
        int getStrBonus(){return m_strbonus;}
        int getAgiBonus(){return m_agibonus;}
        int getTghBonus(){return m_tghbonus;}
        bool isEmpty(){return m_isEmpty;}

    protected:

    private:
        int m_geartype;
        int m_unlocklvl;
        int m_strbonus;
        int m_agibonus;
        int m_tghbonus;
        bool m_isEmpty;
};

#endif // GEARITEM_H
