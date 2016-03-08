#ifndef AGILITY_H
#define AGILITY_H

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

    protected:

    private:
        int m_value;
};

#endif // AGILITY_H
