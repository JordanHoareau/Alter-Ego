#include "GameCharacter/Quests/Quest.h"

Quest::Quest(){
    m_exp = 0;
    m_gold = 0;
    m_state = static_cast<State>(0);
}


//        Quest constructor, used with database?
//        @id     Id quest ID from the data
//        @&items A vector with all the items the quest offers
//        @state  State of the quest, int [0-3], stored in database
Quest::Quest (int id, sf::String name, int exp, int gold, vector<Item*> items, int state){
    m_id = id;
    m_name = name;
    m_exp = exp;
    m_gold = gold;
    m_items = items;
    m_state = static_cast<State>(state);
}
