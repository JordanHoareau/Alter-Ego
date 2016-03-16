#ifndef WEAPONATTACK_H
#define WEAPONATTACK_H

#include "Attack.h"

class WeaponAttack: public Attack
{
    public:
        // Constructors
        WeaponAttack(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int range[2], int aoe_range, bool isLine, bool isAvailable, int weaponID)
            :   Attack(attackID,name,description,unlocklvl,basedamage,range,aoe_range,isLine,isAvailable){
                m_weaponID = weaponID;
        }
        WeaponAttack()
            : Attack(){
                m_weaponID = 0;
        }
        ~WeaponAttack();

        // Initialization method
        // Allow user to instantiate a WeaponAttack object with attributes given as arguments
        virtual void init(int attackID, std::string name, std::string description, int unlocklvl, std::vector<int> basedamage, int Radius[2], int aoeRadius, bool isLine, int weaponID);
        void print();

    protected:

    private:
        int m_weaponID;
};

#endif // WEAPONATTACK_H
