#include "GameEngine/GameEngine.h"
#include "Constants/GameStateConstant.h"
#include "GameCharacter/Characters/Player/Inventory.h"
#include "GameCharacter/Characters/Player/Player.h"
#include "GameCharacter/Items/SellableItem.h"
#include <vector>
#include <iostream>
#include <array>

int main(int argc, char *argv[]){
    // Player tests
    /*
    std::string j = "jordy";
    Inventory* i = new Inventory();
    std::array<int,2> a = {1,1};
    std::vector<Quest> questbook;
    Player* Jordy = new Player(j,1,1,1,male,*i,a,questbook,100,0,0,1);
    Jordy->print();
    */
    GearItem* i = new GearItem(3001);

    std::cout << i->getID() << " " << i->getName() << " - " << i->getDescription() <<
    " | Buy : " << i->getBuyValue() << " - Sell : " << i->getSellValue() << std::endl <<
    " GearType : " << i->getGearType() << "Unlocked at : " << i->getUnlockLvl() << std::endl <<
    "Bonuses : " << i->getStrBonus() << "-" << i->getAgiBonus() << "-" <<  i->getTghBonus() << std::endl;
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
