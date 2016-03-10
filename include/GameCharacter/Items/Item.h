#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
{
    public:
        Item();
    protected:
    private:
        int m_id;
        sf::String m_name;
        int m_quantity;
};

#endif // ITEM_H
