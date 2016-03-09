#include "CinematicContext.h"

CinematicContext CinematicContext::m_CinematicContext;

void CinematicContext::init(){
    cout << "       CinematicContext - Init" << endl;
    m_value = 2;
}
