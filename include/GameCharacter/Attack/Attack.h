#ifndef ATTACK_H
#define ATTACK_H

#include <SFML/Graphics.hpp>

class Attack
{
    public:

    protected:

    private:
        sf::String m_name;
        unsigned int m_basedamage;
        unsigned int m_baseheal;
        unsigned int m_range[2];
        bool isLine;
        sf::String m_description;
};

#endif // ATTACK_H
