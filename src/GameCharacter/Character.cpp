#include "GameCharacter/Character.h"

void Character::updateStats() {
    for(int i=0; i<StatsConstant::StatsNumber; i++){
        m_stats[i] = 0;
        for(int j=0; j<StatsConstant::CaracsNumber; j++){
            m_stats[i] += m_caracs[j] * StatsConstant::CaracsRatio[j][i];
        }
    }
}

void Character::updateCaracs(int str, int agi, int tgh) {

    m_caracs[StatsConstant::StrengthID] += str;
    m_caracs[StatsConstant::AgilityID] += agi;
    m_caracs[StatsConstant::ToughnessID] += tgh;
    updateStats();
}

void Character::print(){
    std::cout <<    "Character : "  << m_name << std::endl <<
                    "Lvl : "        << m_lvl << std::endl <<
                    "Gender : "     << m_gender << std::endl <<
                    "Str : "        << m_caracs[0] << std::endl <<
                    "Agi :"         << m_caracs[1] << std::endl <<
                    "Tgh :"         << m_caracs[2] << std::endl <<
                    "ClassID : "    << m_classID << std::endl <<
                    "WeaponID : "   << m_weaponID << std::endl;
}
