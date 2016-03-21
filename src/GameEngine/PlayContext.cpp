#include "GameEngine/PlayContext.h"

PlayContext PlayContext::m_PlayContext;

void PlayContext::init(){
    cout << "       PlayContext - Init" << endl;
    //set Character0
    m_currentMapID = 0;
}

int PlayContext::loadFromSave(int id){
    cout << "       PlayContext - LoadFromSave " << id << endl;

    // load from save.json the save ID
    return ReturnConstant::Success;
}
