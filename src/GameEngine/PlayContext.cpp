#include "GameEngine/PlayContext.h"

PlayContext PlayContext::m_PlayContext;
Character PlayContext::m_player(sf::String("Kyanto"), 7, 11, 6, boy);

void PlayContext::init(){
    cout << "       PlayContext - Init" << endl;
}
