#include "GameEngine/GameEngine.h"
#include "Constants/GameStateConstant.h"

int main(int argc, char *argv[]){

    GameEngine game;
    game.init("Alter Ego");

    game.changeState(GameStateConstant::IntroState);

    while(game.isRunning()){
		game.handleEvents();
		game.update();
		game.draw();
	}
	game.cleanup();
	cout << "The Real End" << endl;

	return 0;
}
