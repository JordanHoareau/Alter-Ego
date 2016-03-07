#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;

#include "GameEngine/GameState.h"

class GameEngine
{
    public:
        void init(const char* title, int width=640, int height=480);
//        void cleanup();
//
//        void changeState(GameState *state);
//        void pushState(GameState *state);
//        void popState();

        void handleEvents();
//        void update();
//        void draw();

        bool isRunning() { return m_running; }
        void quit() { m_running = false; }

        sf::RenderWindow m_window;

    private:
        vector<GameState*> states;
        bool m_running;
};

#endif // GAMEENGINE_H
