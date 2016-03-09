#ifndef CinematicState_H
#define CinematicState_H

#include "GameStateConstant.h"
#include "GameState.h"
#include "CinematicContext.h"

class CinematicState : public GameState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "CinematicState";
        }

        static CinematicState* instance() {
            return &m_CinematicState;
        }

    private:
        static CinematicState m_CinematicState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;

};

#endif // CinematicState_H
