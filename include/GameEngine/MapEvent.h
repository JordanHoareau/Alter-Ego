#ifndef MAPEVENT_H
#define MAPEVENT_H

#include <iostream>
using namespace std;

class MapEvent
{
    public:
        MapEvent(){}
        MapEvent(int flag, int x, int y);
        virtual ~MapEvent();

        void print(){
            cout << "Je suis un map event, type : " << m_flagReturn << endl;
        }
    private:
        int m_flagReturn;
        int m_idReturn;
        int m_posEvent[2];
};

#endif // MAPEVENT_H
