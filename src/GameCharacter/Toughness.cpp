#include "Toughness.h"

/* ******************************************** */
/*                   Toughness                  */
/* Visible stat to player                       */
/* Improve health and resistance                */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

Toughness::Toughness()
{
    m_value = 0;
}

Toughness::Toughness(int value)
{
    m_value = value;
}

Toughness::~Toughness()
{
    //dtor
}

int Toughness::getValue()
{
    return m_value;
}
