#include "Item.h"

#pragma once

class Potion : public Item
{
    double healPowerPercent;

public:
    Potion(string name, unsigned quant, unsigned cap, double healPower) : Item(name, quant, cap), healPowerPercent(healPower) {}

    //default
    Potion() : Item("Potion", 1, 1), healPowerPercent(25.0) {} 

    unsigned getHealPowerPercent() const { return healPowerPercent; }

    void changeHealPowerPercent(int newHealPower) { healPowerPercent = newHealPower; }

    virtual void use(Mythikin &);
};