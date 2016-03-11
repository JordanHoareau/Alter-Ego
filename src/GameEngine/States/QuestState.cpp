#include "GameEngine/States/QuestState.h"

QuestState QuestState::m_QuestState;

void QuestState::init(){

    if(!m_texture.loadFromFile("img/QuestState.png"))
        cout << "QuestState - Image loading error" << endl;

    m_sprite.setTexture(m_texture);
    cout << "QuestState - Init" << endl;
}

void QuestState::cleanup(){
    cout << "QuestState - Cleanup" << endl;
}

void QuestState::pause(){
    cout << "QuestState - Pause" << endl;
}

void QuestState::resume(){
    cout << "QuestState - Resume" << endl;
}

void QuestState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(GameStateConstant::QuestState);
                break;
            default:
                break;
        }
    }
}

void QuestState::update(GameEngine *game){

}

void QuestState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
