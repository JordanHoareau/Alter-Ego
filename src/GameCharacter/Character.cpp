#include "GameCharacter/Character.h"

Character::Character() {
    for(int i=0; i<StatsConstant::CaracsNumber; i++)
        m_caracs[i] = 0;

    updateStats();

    m_name = "Unnamed";
    m_gender = male;
    m_lvl = 0;
}

Character::Character(sf::String& name, int str, int agi, int tgh, Gender gender, int classID, int weaponID, int lvl) {

    // Identification attributes
    m_name = name;
    m_gender = gender;

    // Battle attributes
    m_lvl = lvl;
    m_currentHealth = m_stats[StatsConstant::HealthID];
    m_caracs[StatsConstant::StrengthID] = str;
    m_caracs[StatsConstant::AgilityID] = agi;
    m_caracs[StatsConstant::ToughnessID] = tgh;
    updateStats();                                          // get stats from caracteristics
    m_stamina = 100;
    m_energy = 100;
    m_classID = classID;
    m_weaponID = weaponID;

    Json::Value root;
    Json::Reader reader;
    // ------------------------
    // STANDARD ATTACK LOAD
    // ------------------------
    std::ifstream attack_file("data\\Attacks\\Attack.json", std::ifstream::binary);
    // Browsing JSON to find attacks according to level
    bool AttackparsingSuccessful = reader.parse( attack_file, root );
    const Json::Value attack_node = root["attacks"];
    if ( !AttackparsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse Attack\n"
                   << reader.getFormattedErrorMessages();
        return;
    }
    for(unsigned int i = 0; i < attack_node.size() ; ++i ){
            // Creating base damage vector from JSON
            std::vector<int> basedamage;
            const Json::Value jbasedamage = attack_node[i]["m_basedamage"];
            for(unsigned int j = 0; j<jbasedamage.size(); j++) basedamage.push_back(jbasedamage[j].asInt());
            // Creating range vector from JSON
            int range[2];
            const Json::Value jrange = attack_node[i]["m_range"];
            for(unsigned int j = 0; j<jrange.size(); j++) range[j] = jrange[j].asInt();
            // attack initialization from current values

            Attack* a = new Attack(
                                    attack_node[i]["m_attackID"].asInt(),
                                    attack_node[i]["m_name"].asString(),
                                    attack_node[i]["m_description"].asString(),
                                    attack_node[i]["m_unlocklvl"].asInt(),
                                    basedamage,
                                    range,
                                    attack_node[i]["m_aoe_radius"].asInt(),
                                    attack_node[i]["m_isLine"].asBool(),
                                    (attack_node[i]["m_unlocklvl"].asInt() <= m_lvl)
                                   );
            m_attacks.push_back(*a);
    }

    // ------------------------
    // CLASS ATTACK LOAD
    // ------------------------
    std::ifstream classattack_file("data\\Attacks\\ClassAttack.json", std::ifstream::binary);
    // Browsing JSON to find attacks according to class and level
    bool ClassAttackparsingSuccessful = reader.parse( classattack_file, root );
    const Json::Value classattack_node = root["classattacks"];
    if ( !ClassAttackparsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse ClassAttack\n"
                   << reader.getFormattedErrorMessages();
        return;
    }

    for(unsigned int i = 0; i < classattack_node.size() ; ++i ){
          if( (classattack_node[i]["m_classID"].asInt() == m_classID) && (classattack_node[i]["m_unlocklvl"].asInt() <= m_lvl) ){
            ClassAttack *ca = new ClassAttack();
            // Creating base damage vector from JSON
            std::vector<int> basedamage;
            const Json::Value jbasedamage = classattack_node[i]["m_basedamage"];

            for(unsigned int j = 0; j<jbasedamage.size(); j++) basedamage.push_back(jbasedamage[j].asInt()); //bd_iterator = basedamage.insert(bd_iterator, 1, jbasedamage[j].asInt());
            // Creating range vector from JSON
            int range[2];
            const Json::Value jrange = classattack_node[i]["m_range"];
            for(unsigned int j = 0; j<jrange.size(); j++) range[j] = jrange[j].asInt();
            // ClassAttack initialization from current values
            ca->init(
                        classattack_node[i]["m_attackID"].asInt(),
                        classattack_node[i]["m_name"].asString(),
                        classattack_node[i]["m_description"].asString(),
                        classattack_node[i]["m_unlocklvl"].asInt(),
                        basedamage,
                        range,
                        classattack_node[i]["m_aoe_radius"].asInt(),
                        classattack_node[i]["m_isLine"].asBool(),
                        classattack_node[i]["m_classID"].asInt()
                     );
            m_attacks.push_back(*ca);
          }
    }

    // ------------------------
    // WEAPON ATTACK LOAD
    // ------------------------
    std::ifstream weaponattack_file("data\\Attacks\\WeaponAttack.json", std::ifstream::binary);
    // Browsing JSON to find attacks according to weapon and level
    bool WeaponAttackparsingSuccessful = reader.parse( weaponattack_file, root );
    const Json::Value weaponattack_node = root["weaponattacks"];
    if ( !WeaponAttackparsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse WeaponAttack\n"
                   << reader.getFormattedErrorMessages();
        return;
    }
    for(unsigned int i = 0; i < weaponattack_node.size() ; ++i ){
          if( (weaponattack_node[i]["m_classID"].asInt() == m_classID) && (weaponattack_node[i]["m_unlocklvl"].asInt() <= m_lvl) ){
            WeaponAttack *wa = new WeaponAttack();
            // Creating base damage vector from JSON
            std::vector<int> basedamage;
            const Json::Value jbasedamage = weaponattack_node[i]["m_basedamage"];
            for(unsigned int j = 0; j<jbasedamage.size(); j++) basedamage.push_back(jbasedamage[j].asInt());
            // Creating range vector from JSON
            int range[2];
            const Json::Value jrange = weaponattack_node[i]["m_range"];
            for(unsigned int j = 0; j<jrange.size(); j++) range[j] = jrange[j].asInt();
            // weaponattack initialization from current values
                wa->init(
                    weaponattack_node[i]["m_attackID"].asInt(),
                    weaponattack_node[i]["m_name"].asString(),
                    weaponattack_node[i]["m_description"].asString(),
                    weaponattack_node[i]["m_unlocklvl"].asInt(),
                    basedamage,
                    range,
                    weaponattack_node[i]["m_aoe_radius"].asInt(),
                    weaponattack_node[i]["m_isLine"].asBool(),
                    weaponattack_node[i]["m_weaponID"].asInt()
                );
                m_attacks.push_back(*wa);
          }
    }
    std::cout << "Attack List : " << std::endl;
    for(unsigned int i = 0; i < m_attacks.size() ; i++){
        Attack& att = m_attacks[i];
        att.print();
    }



    // Offbattle attributes
    m_gold = 0;




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
