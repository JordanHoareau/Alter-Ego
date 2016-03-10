#ifndef QUESTBUFFER_H
#define QUESTBUFFER_H

#include "Quest.h"
#include <vector>
using namespace std;

class QuestBuffer
{
    public:
        QuestBuffer();
    protected:
    private:
        vector<Quest> m_quests;
};

#endif // QUESTBUFFER_H
