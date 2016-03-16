#include "GameEngine/GameEngine.h"
#include "Constants/GameStateConstant.h"
#include "GameCharacter/Inventory.h"
#include "GameCharacter/Character.h"

int main(int argc, char *argv[]){
    std::string j = "Jordy";
    Character* Jordy = new Character(j, 1,1,1, male,0,0,1);

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
