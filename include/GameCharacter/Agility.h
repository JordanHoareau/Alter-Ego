#ifndef AGILITY_H
#define AGILITY_H

#include "Stats.h"

/* ******************************************** */
/*                   Agility                    */
/* Visible stat to player                       */
/* Improve damages, speed and crit_chance       */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

class Agility: public Stats
{
    public:
        Agility();
        Agility(int value);
        virtual ~Agility();

        virtual int getValue();
        virtual void setValue(int value);


    protected:

    private:
        int m_value;
};

#endif // AGILITY_H
