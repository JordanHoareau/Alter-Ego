#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;

#include "Constants/GameStateConstant.h"
class GameState;

class GameEngine
{
    public:
        ~GameEngine(){}
        void init(const sf::String title, int width=640, int height=480);
        void cleanup();

        void changeState(GameState *state, int option=0);
        void changeState(int state, int option=0);
        void pushState(GameState *state, int option=GameStateConstant::NoOption);
        void popState();

        void handleEvents();
        void update();
        void draw();

        bool isRunning() { return m_running; }
        void quit() { m_running = false; }

        sf::RenderWindow m_window;                          //  SFML window, main screen of game

    private:
        vector<GameState*> states;                          //  Stack of game states
        bool m_running;                                     //  boolean which say if the game is running or not
};

#endif // GAMEENGINE_H
