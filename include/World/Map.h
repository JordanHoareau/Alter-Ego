#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "GameCharacter/Character.h"
#include "Constants/MapsConstant.h"
#include <vector>
#include <JSonParser/json-forwards.h>
#include <JSonParser/json.h>
using namespace std;

class Map : public sf::Drawable, public sf::Transformable{
    public:
        Map(){}


        //  MAP LOADING
        //  string tileset : "path\\yourtileset.png"
        int load(int id);
        int handleClick(int x, int y) const;
    protected:

        int m_groupMapID;                               //  GroupMap ID : Number to use for JSON load
        int m_mapCoords[2];

        sf::Texture m_tileset;                          //  Tileset
        sf::VertexArray m_floor;                        //  Floor :                          Z = 0    (walkable - under character)
        sf::VertexArray m_rootEnvironment;              //  RootEnvironment :                Z = 1    (non-walkable)
        sf::VertexArray m_frontEnvironment;             //  FrontEnvironment :               Z = 2    (walkable - over character)


        vector<Character> m_neutrals;                   //  NPC to load on the map

        bool m_isWild;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // MAP_H
