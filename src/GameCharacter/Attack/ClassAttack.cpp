#include "GameCharacter/Attack/ClassAttack.h"

ClassAttack::ClassAttack(sf::String attackname)
{       std::cout << "yo";
        Json::Value root;
        std::cin >> root;
        std::cout << "yo";
        const Json::Value classattack = root["classattack"];std::cout << "yo";
        for(unsigned int index = 0; index < classattack.size(); ++index) std::cout << "yo";

}

ClassAttack::~ClassAttack()
{
}
