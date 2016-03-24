#include "MapEvent.h"

MapEvent::MapEvent(int flag, int x, int y){
    m_flagReturn = flag;
    m_posEvent[0] = x;
    m_posEvent[1] = y;
}

MapEvent::~MapEvent()
{
    //dtor
}
