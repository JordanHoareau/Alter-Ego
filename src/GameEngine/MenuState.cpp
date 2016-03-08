#include "MenuState.h"

MenuState MenuState::m_MenuState;

void MenuState::init(){

    if(!m_texture.loadFromFile("img/MenuState.png"))
        cout << "MenuState - Image loading error" << endl;

    m_sprite.setTexture(m_texture);
    cout << "MenuState - Init" << endl;
}

void MenuState::cleanup(){
    cout << "MenuState - Cleanup" << endl;
}

void MenuState::pause(){
    cout << "MenuState - Pause" << endl;
}

void MenuState::resume(){
    cout << "MenuState - Resume" << endl;
}

void MenuState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(Constants::MenuState);
                break;
            default:
                break;
        }
    }
}

void MenuState::update(GameEngine *game){

}

void MenuState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
