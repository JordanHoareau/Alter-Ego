#include "GameEngine/GameEngine.h"

int main()
{
    GameEngine game;
    game.init("Alter Ego");


    while(game.isRunning()){
		game.handleEvents();
//		game.update();
//		game.draw();
	}

//	game.cleanup();

	return 0;
}
