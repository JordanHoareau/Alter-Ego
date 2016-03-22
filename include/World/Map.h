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

        //                                                                                        width (tile)        height(tile)
        int load(const std::string tileset/*, const int tiles[420]*/){

            int tiles[MapsConstant::MAPSIZE];
            for(int i=0 ; i < MapsConstant::MAPSIZE ; i++) tiles[i] = 0;

            if (!m_tileset.loadFromFile(tileset))
                return false;

            m_vertices.setPrimitiveType(sf::Quads);

            m_vertices.resize(MapsConstant::MAPSIZE * 4);

            for (unsigned int i = 0; i < MapsConstant::HEIGHT; ++i)
                for (unsigned int j = 0; j < MapsConstant::WIDTH; ++j)
                {
                    // on récupère le numéro de tuile courant
                    int tileNumber = tiles[j + i * MapsConstant::WIDTH];

                    // on en déduit sa position dans la texture du tileset
                    int tu = (tileNumber % MapsConstant::TILESET_WIDTH) * MapsConstant::TILE_WIDTH;
                    int tv = (tileNumber/MapsConstant::TILESET_WIDTH);

                    int x = j*MapsConstant::TILE_WIDTH/2;
                    int y = (i * MapsConstant::TILE_HEIGHT/2) + (MapsConstant::TILE_HEIGHT/4)*(j%2);

                    // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                    sf::Vertex* quad = &m_vertices[(j + i * MapsConstant::WIDTH) * 4];

                    // on définit ses quatre coins
                    quad[0].position = sf::Vector2f(x,y);
                    quad[1].position = sf::Vector2f(x + MapsConstant::TILE_WIDTH, y );
                    quad[2].position = sf::Vector2f(x + MapsConstant::TILE_WIDTH, y + MapsConstant::TILE_HEIGHT );
                    quad[3].position = sf::Vector2f(x, y + MapsConstant::TILE_HEIGHT );

                    // on définit ses quatre coordonnées de texture
                    quad[0].texCoords = sf::Vector2f(tu, tv);
                    quad[1].texCoords = sf::Vector2f(tu+MapsConstant::TILE_WIDTH, tv);
                    quad[2].texCoords = sf::Vector2f(tu+MapsConstant::TILE_WIDTH, tv+MapsConstant::TILE_HEIGHT);
                    quad[3].texCoords = sf::Vector2f(tu, tv+MapsConstant::TILE_HEIGHT);
                }

            return true;
        }

    protected:
        int m_id;
        sf::Sprite m_sprite;
        sf::Texture m_tileset;
        sf::VertexArray m_vertices;
        vector<Map> m_adjacentMaps;
        vector<Map> m_subMaps;
    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // on applique la transformation
            states.transform *= getTransform();

            // on applique la texture du tileset
            states.texture = &m_tileset;

            // et on dessine enfin le tableau de vertex
            target.draw(m_vertices, states);
        }
};

#endif // MAP_H
