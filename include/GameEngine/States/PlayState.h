#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Constants/GameStateConstant.h"
#include "GameState.h"
#include "GameEngine/PlayContext.h"

class PlayState : public GameState {
    public:
        void init();
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

    private:
        static PlayState m_PlayState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        PlayContext *m_context;
};

#endif // PLAYSTATE_H
