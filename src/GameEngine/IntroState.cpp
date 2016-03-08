#include "IntroState.h"

IntroState IntroState::m_IntroState;

void IntroState::init(){

    if(!m_texture.loadFromFile("img/IntroState.png"))
        cout << "IntroState - Image loading error" << endl;

    m_sprite.setTexture(m_texture);
    cout << "IntroState - Init" << endl;
}

void IntroState::cleanup(){
    cout << "IntroState - Cleanup" << endl;
}

void IntroState::pause(){
    cout << "IntroState - Pause" << endl;
}

void IntroState::resume(){
    cout << "IntroState - Resume" << endl;
}

void IntroState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(Constants::PlayState);
                break;
            default:
                break;
        }
    }
}

void IntroState::update(GameEngine *game){

}

void IntroState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
