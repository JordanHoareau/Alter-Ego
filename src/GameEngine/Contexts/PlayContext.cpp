#include "GameEngine/Contexts/PlayContext.h"

PlayContext PlayContext::m_PlayContext;

void PlayContext::init(){
    cout << "       PlayContext - Init" << endl;
    m_value = 2;
}
