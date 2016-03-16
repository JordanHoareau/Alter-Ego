#include "GameCharacter/Attacks/ClassAttack.h"

ClassAttack::~ClassAttack()
{
}

void ClassAttack::init(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int Radius[2], int aoeRadius, bool isLine, int classID){
    Attack::init(attackID, name, description, unlocklvl, basedamage, Radius, aoeRadius, isLine);
    m_classID = classID;
}

void ClassAttack::print() {
    Attack::print();
    std::cout << "Class ID : " << m_classID << std::endl;
}
