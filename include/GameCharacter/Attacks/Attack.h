#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class Attack
{
    public:
        Attack(int attackID, sf::String name, sf::String description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoe_radius, bool isLine){
            m_attackID = attackID;
            m_name = name;
            m_description = description;
            m_unlocklvl = unlocklvl;
            m_basedamage = basedamage;
            m_range[0] = range[0];
            m_range[1] = range[1];
            m_aoe_radius = aoe_radius;
            m_isLine = isLine;
        }
        Attack(){
            m_attackID = 0;
            m_name = "";
            m_description = "";
            m_unlocklvl = 0;
            m_range[0] = 0;
            m_range[1] = 0;
            m_aoe_radius = 0;
            m_isLine = false;

        }
        virtual ~Attack();
        virtual void init(int attackID, sf::String name, sf::String description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoeRadius, bool isLine);
        virtual void print();

    protected:
        int m_attackID;
        sf::String m_name;
        sf::String m_description;
        int m_unlocklvl;
        std::vector<int> m_basedamage;
        int m_range[2];
        int m_aoe_radius;
        bool m_isLine;

    private:
};

#endif // ATTACK_H
