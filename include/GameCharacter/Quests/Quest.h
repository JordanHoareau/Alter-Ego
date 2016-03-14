#ifndef QUEST_H
#define QUEST_H

#include <vector>
using namespace std;

#include "GameCharacter/Items/Item.h"

enum State { hidden, available, current, finish };

class Quest {
    public:
        Quest(int id);

    protected:
        // Technical caracteristics
        int m_id;
        vector<int> m_mandatoryQuests;
        State m_state;
        bool m_isStory;

        // Gameplay caracteristics
        sf::String m_name;
        sf::String m_description;
        int m_exp;
        int m_gold;
        vector<Item*> m_items;
};

#endif // QUEST_H
