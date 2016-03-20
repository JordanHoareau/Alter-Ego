#ifndef MAPTILESPRITE_H
#define MAPTILESPRITE_H

#include <SFML/Graphics.hpp>


class MapTileSprite : public sf::Sprite
{
    public:
        MapTileSprite();
        MapTileSprite(const sf::Image &image, const sf::Vector2f &position=sf::Vector2f(0,0),
        const sf::Vector2f &scale=sf::Vector2f(1,1), float rotation=0.f, const sf::Color &color=sf::Color(255,255,255,255));
        virtual ~MapTileSprite();

    protected:

    private:
};

#endif // MAPTILESPRITE_H
