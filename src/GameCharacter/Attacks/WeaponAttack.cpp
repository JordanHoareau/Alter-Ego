#include "GameCharacter/Attacks/WeaponAttack.h"

WeaponAttack::~WeaponAttack()
{
}

void WeaponAttack::init(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int Radius[2], int aoeRadius, bool isLine, int weaponID){
    Attack::init(attackID, name, description, unlocklvl, basedamage, Radius, aoeRadius, isLine);
    m_weaponID = weaponID;
}
