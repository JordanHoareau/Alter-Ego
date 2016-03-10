#ifndef CLASSATTACK_H
#define CLASSATTACK_H

#include "Attack.h"


class ClassAttack : public Attack
{
    public:
        ClassAttack();
        virtual ~ClassAttack();

    protected:

    private:
        sf::String m_class;
};

#endif // CLASSATTACK_H
