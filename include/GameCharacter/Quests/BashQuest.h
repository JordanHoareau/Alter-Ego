#ifndef BASHQUEST_H
#define BASHQUEST_H

#include "GameCharacter/Quests/Quest.h"


class BashQuest : public Quest
{
    public:
        BashQuest();
    protected:
    private:
        int m_objective;
        int m_current;
};

#endif // BASHQUEST_H
