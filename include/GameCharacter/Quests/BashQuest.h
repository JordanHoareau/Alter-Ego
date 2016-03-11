#ifndef BASHQUEST_H
#define BASHQUEST_H

#include "Quest.h"

//              NOT WORKING CLASS ATM (DO NOT INCLUDE IT)

template <typename T>
class BashQuest : public Quest {
    public:
        BashQuest(int id, int state=0) : Quest(id, state){
            m_current = 0;
//            m_objective = JSON.getObjectiveFromId(m_id);
        }
    protected:
        T m_objective;
        int m_current;
};

#endif // BASHQUEST_H
