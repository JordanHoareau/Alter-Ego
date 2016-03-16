#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
{
    public:
        Item(){}
        Item(const Item& i){
            m_id = i.m_id;
            m_name = i.m_name;
            m_description = i.m_description;
        }
        Item(int id, sf::String name, sf::String description){
            m_id = id;
            m_name = name;
            m_description = description;
        }
        int getID() const {return m_id;}
        sf::String getName() const {return m_name;}
        sf::String getDescription() const {return m_description;}

        friend bool operator<(const Item& i1, const Item& i2){
            return i1.getID() < i2.getID();
        }
    protected:
        int m_id;
        sf::String m_name;
        sf::String m_description;
};

#endif // ITEM_H
