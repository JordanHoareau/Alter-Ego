#include "GameEngine/States/PlayState.h"

PlayState PlayState::m_PlayState;

void PlayState::init(){
    cout << "   PlayState - Init" << endl;

    m_context = PlayContext::instance();
    m_context->init();

}

void PlayState::cleanup(){
    cout << "   PlayState - Cleanup" << endl;
}

void PlayState::pause(){
    cout << "   PlayState - Pause" << endl;
}

void PlayState::resume(){
    cout << "   PlayState - Resume" << endl;
}

void PlayState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code){
                    case sf::Keyboard::Left:
                        game->changeState(GameStateConstant::IntroState);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void PlayState::update(GameEngine *game){

}

void PlayState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_map.getSprite(m_sprite));
    game->m_window.display();
}
