#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
{
    public:
        Item(){}
        Item(int id, sf::String name, sf::String description){
            m_id = id;
            m_name = name;
            m_description = description;
        }
    protected:
        int m_id;
        sf::String m_name;
        sf::String m_description;
};

#endif // ITEM_H
