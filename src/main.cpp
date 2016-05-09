#include "GameEngine/GameEngine.h"
#include "Constants/GameStateConstant.h"
#include "GameCharacter/Characters/Player/Inventory.h"
#include "GameCharacter/Characters/Player/Player.h"
#include "GameCharacter/Characters/Ennemy/Ennemy.h"
#include "GameCharacter/Items/ConsumableItem.h"
#include <vector>
#include <iostream>
#include <array>

int main(int argc, char *argv[]){
    // Player tests
    Player p = *(new Player(0));
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
