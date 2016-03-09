#ifndef STATS_H
#define STATS_H
/* ******************************************** */
/*                     Stats                    */
/* Gather used values in combat damage          */
/* calculation with their appropriate methods   */
/*                                              */
/* Parent class : none                          */
/* Children classes : visible stats to player   */
/*                                              */
/* ******************************************** */

class Stats
{
    public:

        virtual ~Stats(){}

        virtual int getValue() = 0;
        virtual void setValue(int value) = 0;

    protected:

    private:
};

#endif // STATS_H
