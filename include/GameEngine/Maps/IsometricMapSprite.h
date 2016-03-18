#ifndef ISOMETRICMAPSPRITE_H
#define ISOMETRICMAPSPRITE_H

#include <SFML/Graphics.hpp>


class IsometricMapSprite : public sf::Sprite
{
    public:
    IsometricMapSprite();
    IsometricMapSprite(const sf::Image &image, const sf::Vector2f &position=sf::Vector2f(0,0),
        const sf::Vector2f &scale=sf::Vector2f(1,1), float rotation=0.f, const sf::Color &color=sf::Color(255,255,255,255));
    ~IsometricMapSprite();

    void SetWorldPosition(float x, float y);
    void SetWorldPosition(const sf::Vector2f &position);
    sf::Vector2f GetWorldPosition() const;

    void SetWorldZ(float z);
    float GetWorldZ(){return m_z;}

    protected:
    sf::Vector2f m_worldpos;
    float m_z;
};

#endif // ISOMETRICMAPSPRITE_H
