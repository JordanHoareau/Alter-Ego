#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <array>

#include "GameCharacter/Character.h"
#include "GameCharacter/Characters/Player/Inventory.h"
#include "GameCharacter/Quests/Quest.h"

class Player : public Character
{
    public:
        Player(std::string& name, int str, int agi, int tgh, Gender gender, Inventory& inventory, std::array<int,2>& position, std::vector<Quest>& questbook, std::array<int,2>& exp, int classID=0, int weaponID=0, int lvl=1)
            :   Character(name, str, agi, tgh, gender,classID,weaponID,lvl){
            m_inventory = *(new Inventory(inventory));
            m_egopoints = 5;
            m_position[0] = position[0]; m_position[1] = position[1];
            m_questbook = questbook;
            m_exp[0] = exp[0]; m_exp[1] = exp[1];
        }
        virtual ~Player();
        Inventory& getInventory(){return m_inventory;}

    protected:

    private:
        Inventory m_inventory;
        int m_egopoints;
        std::array<int,2> m_position;
        std::vector<Quest> m_questbook;
        std::array<int,2> m_exp;

};

#endif // PLAYER_H
