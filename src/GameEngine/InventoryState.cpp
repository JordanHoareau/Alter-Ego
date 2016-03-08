#include "InventoryState.h"

InventoryState InventoryState::m_InventoryState;

void InventoryState::init(){

    if(!m_texture.loadFromFile("img/InventoryState.png"))
        cout << "InventoryState - Image loading error" << endl;

    m_sprite.setTexture(m_texture);
    cout << "InventoryState - Init" << endl;
}

void InventoryState::cleanup(){
    cout << "InventoryState - Cleanup" << endl;
}

void InventoryState::pause(){
    cout << "InventoryState - Pause" << endl;
}

void InventoryState::resume(){
    cout << "InventoryState - Resume" << endl;
}

void InventoryState::handleEvents(GameEngine *game){

    sf::Event event;

    while(game->m_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                game->quit();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                    game->changeState(Constants::InventoryState);
                break;
            default:
                break;
        }
    }
}

void InventoryState::update(GameEngine *game){

}

void InventoryState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(m_sprite);
    game->m_window.display();
}
