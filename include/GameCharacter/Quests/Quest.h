#ifndef QUEST_H
#define QUEST_H

#include <vector>
using namespace std;

#include "GameCharacter/Items/Item.h"

enum State { hide, show, current, finish };

class Quest {
    public:
        Quest(int id, int state);
    protected:
        int m_id;
        sf::String m_name;
        int m_exp;
        int m_gold;
        vector<Item*> m_items;
        State m_state;
};

#endif // QUEST_H
