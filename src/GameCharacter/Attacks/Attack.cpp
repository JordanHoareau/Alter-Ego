#include "GameCharacter/Attacks/Attack.h"
#include <string>

Attack::~Attack()
{
}

void Attack::init(int attackID, sf::String name, sf::String description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoeRadius, bool isLine){
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
    std::cout << "ID : " << m_attackID << std::endl;
}
