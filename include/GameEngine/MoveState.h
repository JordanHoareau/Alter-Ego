#ifndef MoveState_H
#define MoveState_H

#include "Constants.h"
#include "PlayState.h"

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
};

#endif // MoveState_H
