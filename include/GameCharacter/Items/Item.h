#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
{
    public:
        Item(int id);
    protected:
        int m_id;
        sf::String m_name;
        sf::String m_description;
        int m_quantity;
};

#endif // ITEM_H
