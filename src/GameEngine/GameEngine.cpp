#include "GameEngine/GameEngine.h"

void GameEngine::init(const char* title, int width, int height){
    m_window.create(sf::VideoMode(width, height), title);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    m_window.clear();
    m_window.draw(shape);
    m_window.display();

    cout << "GameEngine - Init" << endl;
}

void GameEngine::handleEvents(){
    sf::Event event;

    while(m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                quit();
                cout << "GameEngine - Exit" << endl;
                break;
            default:
                break;
        }
    }
}
