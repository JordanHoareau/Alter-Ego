#include "InventoryContext.h"

InventoryContext InventoryContext::m_InventoryContext;

void InventoryContext::init(){
    cout << "       InventoryContext - Init" << endl;
    m_value = 2;
}
