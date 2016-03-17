#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <string>
#include <JSonParser/json-forwards.h>
#include <JSonParser/json.h>
#include <iostream>
class Item
{
    public:
        Item(){}
        Item(const Item& i){
            m_id = i.m_id;
            m_name = i.m_name;
            m_description = i.m_description;
        }
        Item(int id){
            Json::Value root;
            Json::Reader reader;
            std::ifstream items_file("data\\Items\\Items.json", std::ifstream::binary);
            bool AttackparsingSuccessful = reader.parse( items_file, root );
            if(AttackparsingSuccessful){
                const Json::Value items_node = root["items"];
                for(unsigned int i = 0; i < items_node.size() ; ++i ){
                    const Json::Value item_node=items_node[i];
                    if(item_node["m_itemID"] == id){
                        m_id = item_node["m_itemID"].asInt();
                        m_name = item_node["m_name"].asString();
                        m_description = item_node["m_description"].asString();
                    }
                }
            }else{ return ;}
        }
        int getID() const {return m_id;}
        std::string getName() const {return m_name;}
        std::string getDescription() const {return m_description;}

        friend bool operator<(const Item& i1, const Item& i2){
            return i1.getID() < i2.getID();
        }
    protected:
        int m_id;
        std::string m_name;
        std::string m_description;
};

#endif // ITEM_H
