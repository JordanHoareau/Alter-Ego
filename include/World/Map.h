#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "GameCharacter/Character.h"
#include "Constants/MapsConstant.h"
#include <vector>
using namespace std;

class Map : public sf::Drawable, public sf::Transformable{
    public:
        Map(int id=0);

        int getID(){
            return m_id;
        }

        //  MAP LOADING
        //  string tileset : "path\\yourtileset.png"
        //  string interactiveTileset : "path\\data\\Tiles\\yourInteractiveTileset.png"
        int load(const std::string tileset, const std::string interactiveTileset){
           load(tileset, m_floor);
           load(tileset, m_rootEnvironment);
           load(interactiveTileset, m_interactiveRootEnvironment);
           load(tileset, m_frontEnvironment);
           load(interactiveTileset, m_interactiveFrontEnvironment);
           return 1;
        }

    protected:

        int m_id;                                       //  MAP ID : Number to use for JSON load

        sf::Texture m_tileset;                          //  Tileset : Non interactive tileset
        sf::Texture m_interactiveTileset;
        sf::VertexArray m_floor;                        //  Floor :                         Z = 0   (walkable - under character)
        sf::VertexArray m_rootEnvironment;              //  RootEnvironment :               Z = 1   (non-walkable)
        sf::VertexArray m_interactiveRootEnvironment;   //  InteractiveRootEnvironment :    Z = 2   (non walkable)
        sf::VertexArray m_frontEnvironment;             //  FrontEnvironment :              Z = 2   (walkable - over character)
        sf::VertexArray m_interactiveFrontEnvironment;   //  InteractiveFrontEnvironment :   Z = 3   (walkable - over character)


        vector<Character> m_neutrals;                   //  NPC to load on the map

        vector<Map> m_adjacentsMaps;
        vector<Map> m_subMaps;

        bool m_isWild;



    private:

        int load(const std::string tileset, sf::VertexArray& vertices){

            // DEV : TileMap filled with 0
            int tiles[MapsConstant::MAPSIZE];
            for(int i=0 ; i < MapsConstant::MAPSIZE ; i++) tiles[i] = 0;

            if (!m_tileset.loadFromFile(tileset))
                return false;

            // Vertices : set shape to Quads and number of vertices = numberoftiles*4 (4 vertices/Quads)
            vertices.setPrimitiveType(sf::Quads);
            vertices.resize(MapsConstant::MAPSIZE * 4);

            for (unsigned int i = 0; i < MapsConstant::HEIGHT; ++i)
                for (unsigned int j = 0; j < MapsConstant::WIDTH; ++j)
                {
                    // Get current tileNumber
                    int tileNumber = tiles[j + i * MapsConstant::WIDTH];

                    // Tile position to get in Texture
                    int tu = (tileNumber % MapsConstant::TILESET_WIDTH) * MapsConstant::TILE_WIDTH;
                    int tv = (tileNumber/MapsConstant::TILESET_WIDTH);

                    // Tile position to set on screen
                    int x = j*MapsConstant::TILE_WIDTH/2;
                    int y = (i * MapsConstant::TILE_HEIGHT/2) + (MapsConstant::TILE_HEIGHT/4)*(j%2);

                    // Get effective vertices[4]
                    sf::Vertex* quad = &vertices[(j + i * MapsConstant::WIDTH) * 4];

                    // 4 corners - Screen
                    quad[0].position = sf::Vector2f(x,y);
                    quad[1].position = sf::Vector2f(x + MapsConstant::TILE_WIDTH, y );
                    quad[2].position = sf::Vector2f(x + MapsConstant::TILE_WIDTH, y + MapsConstant::TILE_HEIGHT );
                    quad[3].position = sf::Vector2f(x, y + MapsConstant::TILE_HEIGHT );

                    // 4 corners - Texture
                    quad[0].texCoords = sf::Vector2f(tu, tv);
                    quad[1].texCoords = sf::Vector2f(tu+MapsConstant::TILE_WIDTH, tv);
                    quad[2].texCoords = sf::Vector2f(tu+MapsConstant::TILE_WIDTH, tv+MapsConstant::TILE_HEIGHT);
                    quad[3].texCoords = sf::Vector2f(tu, tv+MapsConstant::TILE_HEIGHT);
                }

            return true;
        }

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // on applique la transformation
            states.transform *= getTransform();

            // on applique la texture du tileset
            states.texture = &m_tileset;

            // et on dessine enfin le tableau de vertex
            target.draw(m_floor, states);
        }
};

#endif // MAP_H
