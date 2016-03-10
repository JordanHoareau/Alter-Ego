#include "GameCharacter/Quests/Quest.h"

//        Quest constructor
//        @id     Id quest ID from the data
//        @state  State of the quest, int [0-3], stored in database
Quest::Quest (int id, int state=0){
    m_id = id;
    m_state = static_cast<State>(state);

//    m_attr = JSON.getQuestFromId(m_id);
}
