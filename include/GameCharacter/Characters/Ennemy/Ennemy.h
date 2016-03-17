#ifndef ENNEMY_H
#define ENNEMY_H

#include <map>
#include <string>
#include <fstream>
#include <JSonParser/json-forwards.h>
#include <JSonParser/json.h>
#include "GameCharacter/Character.h"
#include "GameCharacter/Items/Item.h"
#include "GameCharacter/Items/SellableItem.h"
#include "GameCharacter/Items/ConsumableItem.h"
#include "GameCharacter/Items/GearItem.h"

class Ennemy : public Character
{
    public:
        Ennemy(std::string& name, int str, int agi, int tgh, Gender gender, int ennemyID, int classID, int weaponID, int lvl){
                Json::Value root;
                Json::Reader reader;
                m_ennemyID = ennemyID;
                std::ifstream ennemies_file("data\\Ennemies\\Ennemies.json", std::ifstream::binary);
                // Browsing JSON to find attacks according to level
                bool AttackparsingSuccessful = reader.parse( ennemies_file, root );
                if(AttackparsingSuccessful){
                        const Json::Value ennemies_node = root["ennemies"];
                    for(unsigned int i = 0; i < ennemies_node.size() ; ++i ){
                        const Json::Value ennemy_node=ennemies_node[i];
                        if(ennemy_node["m_ennemyID"] == ennemyID){
                            m_name = ennemies_node["m_name"].asString();
                            m_caracs[StatsConstant::StrengthID] = ennemy_node["m_str"].asInt();
                            m_caracs[StatsConstant::AgilityID] = ennemy_node["m_agi"].asInt();
                            m_caracs[StatsConstant::ToughnessID] = ennemy_node["m_tgh"].asInt();
                            updateStats();
                            m_stamina = 100;
                            m_energy = 100;
                            m_classID = ennemy_node["m_classID"].asInt();
                            m_weaponID = ennemy_node["m_weaponID"].asInt();
                            m_lvl = ennemy_node["m_lvl"].asInt();
                            const Json::Value loottable_node = ennemy_node["m_loottable"];
                            for(unsigned j = 0; j < loottable_node.size(); ++j){
                                int itemID = loottable_node["m_itemID"].asInt();

                                if(itemID < 2000){
                                        Item* it = new Item(itemID);
                                        m_lootrate[*it] += loottable_node[j]["m_rate"].asInt();
                                }else if(itemID < 3000){
                                        SellableItem* it = new SellableItem(itemID);
                                        m_lootrate[*it] += loottable_node[j]["m_rate"].asInt();
                                }else if(itemID < 4000) {
                                        GearItem* it = new GearItem(itemID);
                                        m_lootrate[*it] += loottable_node[j]["m_rate"].asInt();
                                }else{
                                        ConsumableItem* it = new ConsumableItem(itemID);
                                        m_lootrate[*it] += loottable_node[j]["m_rate"].asInt();
                                }
                            }
                        }
                    }
                }else{ return;}


        }
        virtual ~Ennemy();
        void print(){
            std::cout << "ID : " << m_ennemyID << std::endl
                      << "Loot table" << std::endl;
            for (std::map<Item, int>::const_iterator ite = m_lootrate.begin(); ite != m_lootrate.end(); ++ite){
                std::cout << "Name : " << ite->first.getName() << " Rate : " << ite->second << std::endl;
            }
        }

    protected:

    private:
        int m_ennemyID;
        std::map<Item,int> m_lootrate;
};

#endif // ENNEMY_H
