#ifndef QuestState_H
#define QuestState_H

#include "Constants/GameStateConstant.h"
#include "GameEngine/States/MenuState.h"
#include "GameEngine/Contexts/QuestContext.h"

class QuestState : public MenuState {
    public:
        void init();
        void cleanup();

        void pause();
        void resume();

        void handleEvents(GameEngine *game);
        void update(GameEngine *game);
        void draw(GameEngine *game);

        void print(ostream &flux) const{
            flux << "QuestState";
        }

        static QuestState* instance() {
            return &m_QuestState;
        }

    private:
        static QuestState m_QuestState;
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        QuestContext *m_context;
};

#endif // QuestState_H
