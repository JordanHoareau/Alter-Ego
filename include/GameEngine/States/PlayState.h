#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Constants/GameStateConstant.h"
#include "GameState.h"
#include "GameEngine/PlayContext.h"
#include "World/Map.h"

class PlayState : public GameState {
    public:
        void init(int option=GameStateConstant::NoOption);
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "PlayState";
        }

        static PlayState* instance() {
            return &m_PlayState;
        }

    protected:
        static PlayState m_PlayState;
        PlayContext *m_context;

        void reactMapEvent(int event) const;

        Map *m_map;
        vector<Map> m_mainMaps;
        vector<Map> m_subMaps;
};

#endif // PLAYSTATE_H
