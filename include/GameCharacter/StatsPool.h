#ifndef STATSPOOL_H
#define STATSPOOL_H

#include "Stats.h"

class StatsPool: public Stats
{
    public:
        StatsPool();

        virtual int getValue();

    protected:

    private:
        Stats pool[];
};

#endif // STATSPOOL_H
