#include "GameCharacter/Character.h"

Character::Character() {
    for(int i=0; i<StatsConstant::CaracsNumber; i++)
        m_caracs[i] = 0;
    updateStats();

    m_name = "Unamed";
    m_gender = boy;
    m_lvl = 0;
}

Character::Character(sf::String name, int str, int agi, int tgh, Gender gender) {

    m_name = name;
    m_gender = gender;
    m_lvl = 1;
    m_gold = 0;

    m_caracs[StatsConstant::StrengthID] = str;
    m_caracs[StatsConstant::AgilityID] = agi;
    m_caracs[StatsConstant::ToughnessID] = tgh;
    updateStats();

    m_currentHealth = m_stats[StatsConstant::HealthID];
}

Character::Character(int saveID) {

//    m_attr = JSON.getCharacterFromSaveFromId(saveID);
}

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
