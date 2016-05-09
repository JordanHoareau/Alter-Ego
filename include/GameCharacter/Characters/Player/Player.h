#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <array>
#include <cmath>

#include "GameCharacter/Character.h"
#include "GameCharacter/Characters/Player/Inventory.h"
#include "GameCharacter/Quests/Quest.h"

class Player : public Character
{
    public:
        Player(std::string& name, int str, int agi, int tgh, Gender gender, Inventory& inventory, std::array<int,2>& position, std::vector<Quest>& questbook, int exp, int classID=0, int weaponID=0, int lvl=1)
            :   Character(name, str, agi, tgh, gender,classID,weaponID,lvl){
            m_inventory = *(new Inventory(inventory));
            m_egopoints = 5;
            m_position[0] = position[0]; m_position[1] = position[1];
            m_questbook = questbook;
            setExperienceCap(m_lvl);
            earnExperience(exp);
        }
        Player(int ID)
            :   Character(ID){
            setExperienceCap(m_lvl);

            Json::Value root;
            Json::Reader reader;
            // ------------------------
            // STANDARD SAVE LOAD
            // ------------------------
            std::ifstream save_file("data\\Save\\Save.json", std::ifstream::binary);

            bool SaveParsingSuccessful = reader.parse( save_file, root );
            const Json::Value save_node = root["saves"][ID];
            if ( !SaveParsingSuccessful )
            {
                // report to the user the failure and their locations in the document.
                std::cout  << "Failed to parse Save\n"
                           << reader.getFormattedErrorMessages();
                return;
            }

            // EGO POINTS LOAD
            m_egopoints = save_node["m_egopoints"].asInt();


            // INVENTORY LOAD
            m_inventory = *(new Inventory());
            const Json::Value inventory_node = save_node["m_inventory"];
            m_inventory.updateGold(inventory_node["m_gold"].asInt());


            const Json::Value gearitems_node = save_node["m_inventory"]["m_gearslots"];
            for(unsigned int i = 0; i < gearitems_node.size(); i++){
                m_inventory.updateGearItem(gearitems_node[i][0].asInt() ,gearitems_node[i][1].asInt() );
            }

            const Json::Value consumableitems_node = save_node["m_inventory"]["m_consumableslots"];
            for(unsigned int i = 0; i < consumableitems_node.size(); i++){
                m_inventory.updateConsumableItem(consumableitems_node[i][0].asInt() ,consumableitems_node[i][1].asInt() );
            }

            const Json::Value questitems_node = save_node["m_inventory"]["m_questslots"];
            for(unsigned int i = 0; i < questitems_node.size(); i++){
                m_inventory.updateQuestItem(questitems_node[i][0].asInt() ,questitems_node[i][1].asInt() );
            }


            const Json::Value gear_node = save_node["m_inventory"]["m_gear"];
            for(unsigned int i = 0; i < gear_node.size(); i++){
                m_inventory.setGear(gear_node[i].asInt());
            }
            m_inventory.print();
        }
        virtual ~Player();
        Inventory& getInventory(){return m_inventory;}

        void earnExperience(int exp);
        void setExperienceCap(int lvl);
        void print();
        bool isMoving(){
            return !(m_position[0]==m_destination[0] && m_position[1]==m_destination[1]);
        }

    protected:

    private:
        Inventory m_inventory;
        int m_egopoints;
        std::array<int,2> m_position;
        std::array<int,2> m_destination;
        std::vector<Quest> m_questbook;
        std::array<int,2> m_exp;

};

#endif // PLAYER_H
