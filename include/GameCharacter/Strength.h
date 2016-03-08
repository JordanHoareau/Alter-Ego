#ifndef STRENGTH_H
#define STRENGTH_H

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

    protected:

    private:
        int m_value;
};

#endif // STRENGTH_H
