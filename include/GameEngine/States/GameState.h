#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameEngine/GameEngine.h"
#include "Constants/GameStateConstant.h"

class GameState {
    public:
        ~GameState() {}
        virtual void init(int option=GameStateConstant::NoOption) = 0;
        virtual void cleanup() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(GameEngine *game) = 0;
        virtual void update(GameEngine *game) = 0;
        virtual void draw(GameEngine *game) = 0;

        virtual void print(ostream &flux) const{
            flux << "GameState";
        }

        friend ostream &operator<<(ostream &flux, GameState const& state){
            state.print(flux) ;
            return flux;
        }
        bool isViewNeeded(){return m_viewNeeded;}
    protected:
        bool m_viewNeeded;
};

#endif // GAMESTATE_H
