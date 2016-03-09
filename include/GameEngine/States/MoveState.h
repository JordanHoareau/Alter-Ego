#ifndef MoveState_H
#define MoveState_H

#include "GameStateConstant.h"
#include "PlayState.h"
#include "MoveContext.h"

class MoveState : public PlayState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "MoveState";
        }

        static MoveState* instance() {
            return &m_MoveState;
        }

    private:
        static MoveState m_MoveState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        MoveContext *m_context;
};

#endif // MoveState_H
