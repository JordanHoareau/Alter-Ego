#ifndef STRENGTH_H
#define STRENGTH_H

#include "Stats.h"
/* ******************************************** */
/*                   Strength                   */
/* Visible stat to player                       */
/* Improve damages, health and crit_chance      */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

class Strength: public Stats
{
    public:
        Strength();
        Strength(int value);
        virtual ~Strength();

        virtual int getValue();
        virtual void setValue(int value);

    protected:

    private:
        int m_value;
};

#endif // STRENGTH_H
