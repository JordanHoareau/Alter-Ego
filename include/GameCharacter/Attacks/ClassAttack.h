#ifndef CLASSATTACK_H
#define CLASSATTACK_H

#include "Attack.h"

class ClassAttack : public Attack
{
    public:
        ClassAttack(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoe_range, bool isLine, bool isAvailable, int classID)
            :   Attack(attackID,name,description,unlocklvl,basedamage,range,aoe_range,isLine,isAvailable){
                m_classID = classID;
        }
        ClassAttack()
            : Attack(){
                m_classID = 0;
        }
        virtual ~ClassAttack();
        virtual void init(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoeRange, bool isLine, int classID);
        void print();
    protected:

    private:
        int m_classID;
};

#endif // CLASSATTACK_H
