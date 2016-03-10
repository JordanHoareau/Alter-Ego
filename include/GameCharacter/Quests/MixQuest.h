#ifndef MIXQUEST_H
#define MIXQUEST_H

#include "GameCharacter/Quests/BashQuest.h"


class MixQuest : public BashQuest
{
    public:
        MixQuest();
    protected:
    private:
        vector<BashQuest*> m_quests;
};

#endif // MIXQUEST_H
