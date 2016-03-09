#include "GameEngine/States/SettingsState.h"

SettingsState SettingsState::m_SettingsState;

void SettingsState::init(){

    if(!m_texture.loadFromFile("img/SettingsState.png"))
        cout << "SettingsState - Image loading error" << endl;

    m_context = SettingsContext::instance();
    m_context->init();

    m_sprite.setTexture(m_texture);
    cout << "SettingsState - Init" << endl;
}

void SettingsState::cleanup(){
    cout << "SettingsState - Cleanup" << endl;
}

void SettingsState::pause(){
    cout << "SettingsState - Pause" << endl;
}

void SettingsState::resume(){
    cout << "SettingsState - Resume" << endl;
}

void SettingsState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(GameStateConstant::SettingsState);
                break;
            default:
                break;
        }
    }
}

void SettingsState::update(GameEngine *game){

}

void SettingsState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
