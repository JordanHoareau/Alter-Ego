#include "World/Map.h"

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Apply transformation
    states.transform *= getTransform();

    // Apply texture
    states.texture = &m_tileset;

    // Draw layers
    target.draw(m_floor, states);
    target.draw(m_rootEnvironment, states);
    target.draw(m_frontEnvironment, states);
}


int Map::load(int id){
            Json::Value root;
            Json::Reader reader;
            std::ifstream maps_file("data\\Maps\\Maps.json", std::ifstream::binary);
            bool MapparsingSuccessful = reader.parse( maps_file, root );
            if(MapparsingSuccessful){
                m_groupMapID = root["mapsID"][id]["m_groupMapID"].asInt();
                m_mapCoords[0] = root["mapsID"][id]["m_mapCoords"][0].asInt();
                m_mapCoords[1] = root["mapsID"][id]["m_mapCoords"][1].asInt();
            }
            std::cout << "GroupMapID : " << m_groupMapID << std::endl << "Coordonnées Map : ["<<m_mapCoords[0]<<","<<m_mapCoords[1]<<"]"<< std::endl;
            //  DEV : TileMap filled with 0
            int tiles[MapsConstant::MAPSIZE];
            for(int i=0 ; i < MapsConstant::MAPSIZE ; i++) tiles[i] = 0;
            std::string path = "data\\Tiles\\";
            path.append(root["mapsID"][id]["m_tileset"].asString());
            path.append(".png");
            if (!m_tileset.loadFromFile( path ))
                return false;

            ///////////////////////////////////////
            //  FLOOR LOADING

            // Vertices : set shape to Quads and number of m_ground = numberoftiles*4 (4 m_ground/Quads)
            m_floor.setPrimitiveType(sf::Quads);
            m_floor.resize(MapsConstant::MAPSIZE * 4);

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

                    // Get effective m_floor[4]
                    sf::Vertex* quad = &m_floor[(j + i * MapsConstant::WIDTH) * 4];

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


            ///////////////////////////////////////
            //  ROOT LOADING

            // Vertices : set shape to Quads and number of vertices = numberoftiles*4 (4 vertices/Quads)
            m_rootEnvironment.setPrimitiveType(sf::Quads);
            m_rootEnvironment.resize(MapsConstant::MAPSIZE * 4);

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

                    // Get effective m_rootEnvironment[4]
                    sf::Vertex* quad = &m_rootEnvironment[(j + i * MapsConstant::WIDTH) * 4];

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

            ///////////////////////////////////////
            //  FRONT LOADING

            // Vertices : set shape to Quads and number of vertices = numberoftiles*4 (4 vertices/Quads)
            m_frontEnvironment.setPrimitiveType(sf::Quads);
            m_frontEnvironment.resize(MapsConstant::MAPSIZE * 4);

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

                    // Get effective frontEnvironment[4]
                    sf::Vertex* quad = &m_frontEnvironment[(j + i * MapsConstant::WIDTH) * 4];

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
//>>>>>>> origin/feature-maps
        }



    ///////////////////////////////////////
    //  ROOT LOADING

    // Vertices : set shape to Quads and number of vertices = numberoftiles*4 (4 vertices/Quads)
    m_rootEnvironment.setPrimitiveType(sf::Quads);
    m_rootEnvironment.resize(MapsConstant::MAPSIZE * 4);

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

            // Get effective m_rootEnvironment[4]
            sf::Vertex* quad = &m_rootEnvironment[(j + i * MapsConstant::WIDTH) * 4];

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

    ///////////////////////////////////////
    //  FRONT LOADING

    // Vertices : set shape to Quads and number of vertices = numberoftiles*4 (4 vertices/Quads)
    m_frontEnvironment.setPrimitiveType(sf::Quads);
    m_frontEnvironment.resize(MapsConstant::MAPSIZE * 4);

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

            // Get effective frontEnvironment[4]
            sf::Vertex* quad = &m_frontEnvironment[(j + i * MapsConstant::WIDTH) * 4];

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

int Map::handleClick(int x, int y) const{
    return -1;
}
