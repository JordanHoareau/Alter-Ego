#ifndef ISOMETRICMAPNODE_H
#define ISOMETRICMAPNODE_H

#include <SFML/Graphics.hpp>
#include "GameEngine/Maps/IsometricMapSprite.h"
#include <list>

class IsometricMapNode
{
    public:
    IsometricMapNode();
    ~IsometricMapNode();

    void drawFloors(sf::RenderWindow *win, sf::Color &color);
    void drawObjects(sf::RenderWindow *win, sf::Color &color);
    void drawWalls(sf::RenderWindow *win, sf::Color &color);
    void drawRoofs(sf::RenderWindow *win, sf::Color &color);

    void addFloor(IsometricMapSprite *s);
    void addWall(IsometricMapSprite *s);
    void addRoof(IsometricMapSprite *s);

    void insertSprite(IsometricMapSprite *s);
    void removeSprite(IsometricMapSprite *s);
    void clear();


    protected:

    std::list<IsometricMapSprite *> m_floors, m_walls, m_roofs, m_objects;
};
#endif // ISOMETRICMAPNODE_H
