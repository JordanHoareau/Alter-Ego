#ifndef DIALOGQUEST_H
#define DIALOGQUEST_H

#include "Quest.h"
#include "GameCharacter/Character.h"

class DialogQuest : public Quest {
    public:
        DialogQuest(int id, int state);
    protected:
    private:
        int m_targetID;
};

#endif // DIALOGQUEST_H
