#ifndef InventoryCONTEXT_H
#define InventoryCONTEXT_H

#include "GameContext.h"
#include "MenuContext.h"
#include <iostream>
using namespace std;

class InventoryContext : public MenuContext {

    public:
        void init();
        static InventoryContext* instance() {
            return &m_InventoryContext;
        }

    protected:
    private:
        static InventoryContext m_InventoryContext;
        int m_value;
};

#endif // InventoryCONTEXT_H
