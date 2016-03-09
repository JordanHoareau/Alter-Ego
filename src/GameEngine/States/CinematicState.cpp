#include "GameEngine/States/CinematicState.h"

CinematicState CinematicState::m_CinematicState;

void CinematicState::init(){

    if(!m_texture.loadFromFile("img/CinematicState.png"))
        cout << "CinematicState - Image loading error" << endl;

    m_context = CinematicContext::instance();
    m_context->init();

    m_sprite.setTexture(m_texture);
    cout << "CinematicState - Init" << endl;
}

void CinematicState::cleanup(){
    cout << "CinematicState - Cleanup" << endl;
}

void CinematicState::pause(){
    cout << "CinematicState - Pause" << endl;
}

void CinematicState::resume(){
    cout << "CinematicState - Resume" << endl;
}

void CinematicState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(GameStateConstant::PlayState);
                break;
            default:
                break;
        }
    }
}

void CinematicState::update(GameEngine *game){

}

void CinematicState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
