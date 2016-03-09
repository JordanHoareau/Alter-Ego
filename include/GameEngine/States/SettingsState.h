#ifndef SettingsState_H
#define SettingsState_H

#include "Constants/GameStateConstant.h"
#include "GameEngine/States/MenuState.h"
#include "GameEngine/Contexts/SettingsContext.h"

class SettingsState : public MenuState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "SettingsState";
        }

        static SettingsState* instance() {
            return &m_SettingsState;
        }

    private:
        static SettingsState m_SettingsState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        SettingsContext *m_context;
};

#endif // SettingsState_H
