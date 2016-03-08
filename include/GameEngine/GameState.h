#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameEngine.h"
#include "GameContext.h"

class GameState
{
    public:
        virtual void init() = 0;
        virtual void cleanup() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(GameEngine *game) = 0;
        virtual void update(GameEngine *game) = 0;
        virtual void draw(GameEngine *game) = 0;

        virtual void print(ostream &flux) const{
            flux << "state";
        }

        friend ostream &operator<<(ostream &flux, GameState const& state){
            state.print(flux) ;
            return flux;
        }
    protected:
        GameContext m_context;
    private:
};

#endif // GAMESTATE_H
