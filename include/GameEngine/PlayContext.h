#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H

#include "Constants/StatsConstant.h"
#include "GameCharacter/Character.h"
#include "World/Map.h"
#include <vector>
#include <iostream>
using namespace std;

class PlayContext {

    public:
        void init();
        static PlayContext* instance() {
            return &m_PlayContext;
        }
    private:
        static PlayContext m_PlayContext;
        static Character m_player;
        static Map m_currentMap;
};

#endif // PLAYCONTEXT_H
