#ifndef MenuState_H
#define MenuState_H

#include "Constants/GameStateConstant.h"
#include "PlayState.h"

class MenuState : public PlayState {
    public:
        void init(int option=GameStateConstant::NoOption);
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "MenuState";
        }

        static MenuState* instance() {
            return &m_MenuState;
        }

    private:
        static MenuState m_MenuState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
};

#endif // MenuState_H
