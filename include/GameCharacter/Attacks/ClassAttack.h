#ifndef CLASSATTACK_H
#define CLASSATTACK_H

#include <iostream>
#include <fstream>
#include <JSonParser/json.h>
#include <SFML/Graphics.hpp>

#include "Attack.h"

class ClassAttack : public Attack
{
    public:
        ClassAttack(int classID);
        virtual ~ClassAttack();

    protected:

    private:
        sf::String m_class;
        int m_lvlunlock;
};

#endif // CLASSATTACK_H
