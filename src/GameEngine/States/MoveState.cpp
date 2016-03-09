#include "GameEngine/States/MoveState.h"

MoveState MoveState::m_MoveState;

void MoveState::init(){

    if(!m_texture.loadFromFile("img/MoveState.png"))
        cout << "MoveState - Image loading error" << endl;

    m_context = MoveContext::instance();
    m_context->init();

    m_sprite.setTexture(m_texture);
    cout << "MoveState - Init" << endl;
}

void MoveState::cleanup(){
    cout << "MoveState - Cleanup" << endl;
}

void MoveState::pause(){
    cout << "MoveState - Pause" << endl;
}

void MoveState::resume(){
    cout << "MoveState - Resume" << endl;
}

void MoveState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(GameStateConstant::MoveState);
                break;
            default:
                break;
        }
    }
}

void MoveState::update(GameEngine *game){

}

void MoveState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
