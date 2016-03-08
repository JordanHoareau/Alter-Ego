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

//    Initialization of the Game Engine
//    @title : Title of the window
//    Initialize the game engine, create the window
void GameEngine::init(const string* title, int width, int height){
    m_window.create(sf::VideoMode(width, height), title);
    m_running = true;

    cout << "GameEngine - Init" << endl;
}

//        Cleap up the game engine
//        Before stopping, clean up every states, then close the game window
void GameEngine::cleanup(){
    // Delete all states
    while(!states.empty()){
        states.back()->cleanup();
        states.pop_back();
    }

    cout << "GameEngine - cleanup" << endl;
    m_window.close();
}

//        Change the state
//        @state The new state
//        Clean up the old state and push the new one
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

//        Change the state using its constant index
//        @state The index of the state (cf Constants.h)
//        Call the other ChangeState method with a State object
void GameEngine::changeState(int state){
    switch(state){
        case Constants::IntroState:
            changeState(IntroState::instance());
            break;
        case Constants::PlayState:
            changeState(PlayState::instance());
            break;
        case Constants::CinematicState:
            changeState(CinematicState::instance());
            break;
        case Constants::MoveState:
            changeState(MoveState::instance());
            break;
        case Constants::BattleState:
            changeState(BattleState::instance());
            break;
        case Constants::MenuState:
            changeState(MenuState::instance());
            break;
        case Constants::InventoryState:
            changeState(InventoryState::instance());
            break;
        case Constants::QuestState:
            changeState(QuestState::instance());
            break;
        case Constants::SettingsState:
            changeState(SettingsState::instance());
            break;
        default:
            cout << "GameEngine - ChangeState ERROR INVALID INDEX" << endl;
            break;
    }
}

//        Push state
//        @state The new state
//        Pause the current state and push the new One
//        The old state isn't popped, it will be resumed when the new one will be popped
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

//        Pop state
//        Pop the current state, then resume to the last one
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

//        Give the handleEvents task to the current state
void GameEngine::handleEvents(){
    // HandleEvents from current state
    states.back()->handleEvents(this);
}

//        Give the update task to the current state
void GameEngine::update(){
	// let the state update the game
	states.back()->update(this);
}

//        Give the draw task to the current state
void GameEngine::draw(){
	// let the state draw the screen
	states.back()->draw(this);
}
