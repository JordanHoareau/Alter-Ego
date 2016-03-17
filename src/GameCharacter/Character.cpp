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
