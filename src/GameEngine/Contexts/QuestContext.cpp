#include "GameEngine/Contexts/QuestContext.h"

QuestContext QuestContext::m_QuestContext;

void QuestContext::init(){
    cout << "       QuestContext - Init" << endl;
    m_value = 2;
}
