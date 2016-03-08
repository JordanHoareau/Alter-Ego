#ifndef CHARSTAT_H
#define CHARSTAT_H

#include <vector>
/* ******************************************** */
/*                  CharStats                   */
/* Gather visible values to player              */
/*                                              */
/* Parent class : Stats                         */
/* Children classes : none                      */
/*                                              */
/* ******************************************** */

class CharStat: public Stats
{
    public:
        CharStat();
        CharStat(int children_size);
        virtual ~CharStat();

        // Setting stats method
        virtual void setStats();

    protected:

    private:
        vector <Stats*> m_children;
        int m_ChildrenSize;
};

#endif // CHARSTAT_H
