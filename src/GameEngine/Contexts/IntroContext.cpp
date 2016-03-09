#include "GameEngine/Contexts/IntroContext.h"

IntroContext IntroContext::m_IntroContext;

void IntroContext::init(){
    cout << "       IntroContext - Init" << endl;
    m_value = 2;
}
