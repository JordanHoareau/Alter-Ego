#include "GameCharacter/Attacks/Attack.h"
#include <string>

Attack::~Attack()
{
}

void Attack::init(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoeRadius, bool isLine){
    m_attackID = attackID;
    m_name = name;
    m_description = description;
    m_unlocklvl = unlocklvl;
    m_basedamage = basedamage;
    m_range[0] = range[0]; m_range[1] = range[1];
    m_aoe_radius = aoeRadius;
    m_isLine = isLine;
}

void Attack::print(){
    std::cout <<    "ID : " << m_attackID << std::endl <<
                    "Name : " << m_name << std::endl <<
                    "Description : " << m_description << std::endl <<
                    "Unlock lvl : " << m_unlocklvl << std::endl <<
                    "BaseDamage : ";
    for(std::vector<int>::const_iterator i = m_basedamage.begin(); i!=m_basedamage.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl <<
                    "Range : " << m_range[0] << "-" << m_range[1] << std::endl<<
                    "AoE Radius : " << m_aoe_radius << std::endl <<
                    "Line : " << m_isLine << std::endl;
}
