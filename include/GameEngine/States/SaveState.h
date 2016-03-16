#ifndef SAVESTATE_H
#define SAVESTATE_H

#include "Constants/GameStateConstant.h"
#include "MenuState.h"

class SaveState : public MenuState {
    public:
        void init(int option=GameStateConstant::NoOption);
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "SaveState";
        }

        static SaveState* instance() {
            return &m_SaveState;
        }

    private:
        static SaveState m_SaveState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
};

#endif // SAVESTATE_H
