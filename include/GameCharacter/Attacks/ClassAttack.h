#ifndef CLASSATTACK_H
#define CLASSATTACK_H

#include "Attack.h"

class ClassAttack : public Attack
{
    public:
        ClassAttack(int attackID, sf::String name, sf::String description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoe_range, bool isLine, int classID)
            :   Attack(attackID,name,description,unlocklvl,basedamage,range,aoe_range,isLine){
                m_classID = classID;
        }
        ClassAttack()
            : Attack(){
                m_classID = 0;
        }
        virtual ~ClassAttack();
        virtual void init(int attackID, sf::String name, sf::String description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoeRange, bool isLine, int classID);
    protected:

    private:
        int m_classID;
};

#endif // CLASSATTACK_H
