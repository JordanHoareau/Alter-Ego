#include "GameCharacter/Stats/Toughness.h"

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

Toughness::~Toughness()
{
    delete this;
}
Toughness::Toughness(int value)
{
    m_value = value;
}

int Toughness::getValue()
{
    return m_value;
}

void Toughness::setValue(int value)
{
    m_value = value;
}
