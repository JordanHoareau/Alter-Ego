#include "BattleState.h"

BattleState BattleState::m_BattleState;

void BattleState::init(){

    if(!m_texture.loadFromFile("img/BattleState.png"))
        cout << "BattleState - Image loading error" << endl;

    m_sprite.setTexture(m_texture);
    cout << "BattleState - Init" << endl;
}

void BattleState::cleanup(){
    cout << "BattleState - Cleanup" << endl;
}

void BattleState::pause(){
    cout << "BattleState - Pause" << endl;
}

void BattleState::resume(){
    cout << "BattleState - Resume" << endl;
}

void BattleState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(GameStateConstant::BattleState);
                break;
            default:
                break;
        }
    }
}

void BattleState::update(GameEngine *game){

}

void BattleState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
