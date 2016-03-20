#include "World/Map.h"

Map::Map(int id){
    m_id = id;

    // TEMPORAIRE TEST
    m_tileset.loadFromFile("img/PlayState.png");
    m_sprite.setTexture(m_tileset);

//    m_texture = JSON.getMapFromId(m_id);
//    m_sprite.setTexture(m_texture);
//    for each (QUEST in MAP)
//        m_questBuffer = JSON.getQuestsFromId(QuestID)
//
//    for each (CHAR in MAP)
//        m_charBuffer = JSON.getCharsFromId(CharID)
}
