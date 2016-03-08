#include "GameEngine.h"
#include "GameState.h"
#include "IntroState.h"
#include "PlayState.h"
#include "CinematicState.h"
#include "MoveState.h"
#include "BattleState.h"
#include "MenuState.h"
#include "QuestState.h"
#include "InventoryState.h"
#include "SettingsState.h"


void GameEngine::init(const char* title, int width, int height){
    m_window.create(sf::VideoMode(width, height), title);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    m_window.clear();
    m_window.draw(shape);
    m_window.display();

    cout << "GameEngine - Init" << endl;
}

void GameEngine::cleanup(){
    // Delete all states
    while(!states.empty()){
        states.back()->cleanup();
        states.pop_back();
    }

    cout << "GameEngine - cleanup" << endl;
    m_window.close();
}

void GameEngine::changeState(GameState *state){
    // Delete the current state
    if(!states.empty()){
        states.back()->cleanup();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init();
    cout << "GameEngine - changeState - " << *state << endl;
}

void GameEngine::changeState(int state){
    switch(state){
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::PlayState:
            changeState(PlayState::instance());
            break;
        /*
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        */
        default:
            cout << "GameEngine - ChangeState ERROR INVALID INDEX" << endl;
            break;
    }
}

void GameEngine::pushState(GameState *state)
{
	// pause current state
	if (!states.empty())
		states.back()->pause();

	// store and init the new state
	states.push_back(state);
	states.back()->init();
    cout << "GameEngine - pushState" << endl;
}

void GameEngine::popState()
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty())
		states.back()->resume();
    cout << "GameEngine - popState" << endl;
}

void GameEngine::handleEvents(){
    // HandleEvents from current state
    states.back()->handleEvents(this);
}

void GameEngine::update(){
	// let the state update the game
	states.back()->update(this);
}

void GameEngine::draw(){
	// let the state draw the screen
	states.back()->draw(this);
}
