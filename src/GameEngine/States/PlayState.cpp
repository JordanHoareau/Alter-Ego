#include "GameEngine/States/PlayState.h"

PlayState PlayState::m_PlayState;

void PlayState::init(int option){
    cout << "   PlayState - Init" << endl;
    Map* mymap = new Map(0);

    mymap->load((string) "data\\Tiles\\tile.png");
    m_map = mymap;


    m_context = PlayContext::instance();
//    @option 0 means initialization, 1-2-3 is the number of the save the be loaded
    if(option==0)
        m_context->init();
    else if(option>0 && option<4)
        m_context->loadFromSave(option);


//    m_map = getMapFromID(m_context->getCurrentMapID());
    //m_map = new Map();     // TEMPORARY TEST
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
//    if(m_map->getID() != m_context->getCurrentMapID())
//        m_map = getMapFromID(m_context->getCurrentMapID());

}

void PlayState::draw(GameEngine *game){
    game->m_window.clear();
    game->m_window.draw(*m_map);
    game->m_window.display();
}
