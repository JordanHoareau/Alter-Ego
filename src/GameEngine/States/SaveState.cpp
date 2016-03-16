#include "GameEngine/States/SaveState.h"

SaveState SaveState::m_SaveState;

void SaveState::init(int option){
    cout << "SaveState - Init" << endl;

    if(!m_texture.loadFromFile("img/SaveState.png"))
        cout << "   SaveState - Image loading error" << endl;

    m_sprite.setTexture(m_texture);
}

void SaveState::cleanup(){
    cout << "SaveState - Cleanup" << endl;
}

void SaveState::pause(){
    cout << "SaveState - Pause" << endl;
}

void SaveState::resume(){
    cout << "SaveState - Resume" << endl;
}

void SaveState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(GameStateConstant::SaveState);
                break;
            default:
                break;
        }
    }
}

void SaveState::update(GameEngine *game){

}

void SaveState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
