#pragma once

#include "Item.h"


using namespace std;

class BattleItem : public Item
{

public:
    // Constructor for Item
    BattleItem(string name, unsigned quant, unsigned cap, unsigned price) : Item(name, quant, cap, price)
    {
    };

    virtual void use(Mythikin& mythikin) = 0; // subclasses must implement this method
};