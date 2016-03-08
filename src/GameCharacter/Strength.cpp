#include "Strength.h"

/* ******************************************** */
/*                   Strength                   */
/* Visible stat to player                       */
/* Improve damages, health and crit_chance      */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

Strength::Strength()
{
    m_value = 0;
}

Strength::Strength(int value)
{
    m_value = value;
}

Strength::~Strength()
{

}

int Strength::getValue()
{
    return m_value;
}
