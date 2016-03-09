#ifndef InventoryState_H
#define InventoryState_H

#include "Constants/GameStateConstant.h"
#include "GameEngine/States/MenuState.h"
#include "GameEngine/Contexts/InventoryContext.h"

class InventoryState : public MenuState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "InventoryState";
        }

        static InventoryState* instance() {
            return &m_InventoryState;
        }

    private:
        static InventoryState m_InventoryState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        InventoryContext *m_context;
};

#endif // InventoryState_H
