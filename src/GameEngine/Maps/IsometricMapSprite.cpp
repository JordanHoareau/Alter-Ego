#include "IsometricMapSprite.h"

IsometricMapSprite::IsometricMapSprite()
{
    //ctor
}

IsometricMapSprite::~IsometricMapSprite()
{
    //dtor
}
// Function to convert a world position to a screen (view) position
// ScreenX = 2*WorldX - 2*WorldY
// ScreenY = WorldX + WorldY
sf::Vector2f WorldToScreen(sf::Vector2f v)
{
    return sf::Vector2f(2.0f*v.x - 2.0f*v.y, v.x + v.y);
}

// Function to convert a screen (view) position to a world position
// WorldX = (ScreenX + 2*ScreenY)/4
// WorldY = (2*ScreenY - ScreenX)/4
sf::Vector2f ScreenToWorld(sf::Vector2f v)
{
    return sf::Vector2f((v.x+2.0f*v.y)/4.0f, (2.0f*v.y-v.x)/4.0f);
}

void IsometricMapSprite::SetWorldPosition(const sf::Vector2f &position)
{
    m_worldpos=position;
    sf::Vector2f screenpos=WorldToScreen(m_worldpos);
    screenpos.y -= m_z;
    setPosition(screenpos);
}

void IsometricMapSprite::SetWorldZ(float z)
{
    m_z=z;
    sf::Vector2f screenpos=WorldToScreen(m_worldpos);
    screenpos.y -= m_z;
    setPosition(screenpos);
}
