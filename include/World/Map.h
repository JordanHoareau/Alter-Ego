#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "GameCharacter/Character.h"
#include <vector>
using namespace std;

class Map {
    public:
        Map() {}
        Map(int id);

        sf::Sprite getSprite(){
            return m_sprite;
        }

    protected:
        int m_id;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
//        vector<NeutralCharacter> m_neutrals;
//        int spawnRate;
//        map<FoeCharacter,int> m_foesSpawnTable;
        vector<Map> m_adjacentMaps;
        vector<Map> m_subMaps;
};

#endif // MAP_H
