#include "GameEngine.h"
#include "Constants.h"

int main(int argc, char *argv[]){

    GameEngine game;
    game.init("Alter Ego");

    game.changeState(Constants::IntroState);

    while(game.isRunning()){
		game.handleEvents();
		game.update();
		game.draw();
	}

	game.cleanup();

	return 0;
}
