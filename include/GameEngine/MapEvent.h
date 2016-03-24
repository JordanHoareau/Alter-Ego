#ifndef MAPEVENT_H
#define MAPEVENT_H

#include <array>
#include <iostream>
using namespace std;

class MapEvent
{
    public:
        MapEvent(){}
        MapEvent(int flag, int x, int y);   //  Constructor moveEvent
        MapEvent(int flag, int id);         //  Constructor idEvent
        virtual ~MapEvent();

        int getFlag(){
            return m_flagReturn;
        }
        std::array<int,2> getDestination(){
            return m_posEvent;
        }
    private:
        int m_flagReturn;
        int m_idReturn;
        std::array<int,2> m_posEvent;
};

#endif // MAPEVENT_H
