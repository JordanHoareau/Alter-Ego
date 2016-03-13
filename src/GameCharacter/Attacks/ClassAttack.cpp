#include "GameCharacter/Attacks/ClassAttack.h"

ClassAttack::~ClassAttack()
{
}

void ClassAttack::init(int attackID, sf::String name, sf::String description, int unlocklvl, std::vector<int> basedamage, int Radius[2], int aoeRadius, bool isLine, int classID){
    Attack::init(attackID, name, description, unlocklvl, basedamage, Radius, aoeRadius, isLine);
    m_classID = classID;
}
