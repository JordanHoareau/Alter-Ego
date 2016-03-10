#ifndef TOUGHNESS_H
#define TOUGHNESS_H

#include "Stats.h"
/* ******************************************** */
/*                   Toughness                  */
/* Visible stat to player                       */
/* Improve health and resistance                */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

class Toughness: public Stats
{
    public:
        Toughness();
        Toughness(int value);
        virtual ~Toughness();

        virtual int getValue();
        virtual void setValue(int value);
    protected:

    private:
        int m_value;
};

#endif // TOUGHNESS_H