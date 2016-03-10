#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H

#include "GameContext.h"
#include "GameCharacter/Character.h"
#include "World/Map.h"
#include <vector>
#include <iostream>
using namespace std;

class PlayContext : public GameContext {

    public:
        void init();
        static PlayContext* instance() {
            return &m_PlayContext;
        }

    protected:
    private:
        static PlayContext m_PlayContext;
        Character m_player;
        vector<Map> m_maps;
};

#endif // PLAYCONTEXT_H
