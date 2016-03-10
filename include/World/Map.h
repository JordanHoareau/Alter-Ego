#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "GameCharacter/Character.h"
#include <vector>
using namespace std;

class Map {
    public:
        Map(int id);

    protected:
        int m_id;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        vector<Character> m_chars;
};

#endif // MAP_H
