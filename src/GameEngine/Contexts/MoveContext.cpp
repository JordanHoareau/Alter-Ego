#include "MoveContext.h"

MoveContext MoveContext::m_MoveContext;

void MoveContext::init(){
    cout << "       MoveContext - Init" << endl;
    m_value = 2;
}
