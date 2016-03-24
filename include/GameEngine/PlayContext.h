#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H

#include "Constants/StatsConstant.h"
#include "Constants/ReturnConstant.h"
#include "GameCharacter/Character.h"
#include "World/Map.h"
#include <vector>
#include <iostream>
using namespace std;

class PlayContext {

    public:
        ~PlayContext() {}
        void init();
        int loadFromSave(int id);

        int getCurrentMapID(){
            return m_currentMapID;
        }
        void setCurrentMapID(int id){
            m_currentMapID = id;
        }

        static PlayContext* instance() {
            return &m_PlayContext;
        }

        //DEVTEST !!
        void changeMap(){
            m_currentMapID = (m_currentMapID+1)%3;
        }



    private:
        static PlayContext m_PlayContext;
        static Character m_player;
        int m_currentMapID;
};

#endif // PLAYCONTEXT_H
