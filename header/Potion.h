#include "Item.h"

#pragma once

class Potion : protected Item
{
    double healPowerPercent;

public:
    Potion(string name, unsigned quant, unsigned cap, unsigned price, double healPower) : Item(name, quant, cap, price), healPowerPercent(healPower) {}

    // default constructor
    Potion() : Item("Potion", 1, 1, 200), healPowerPercent(25.0) {}

    const unsigned getHealPowerPercent() const { return healPowerPercent; }

    void setHealPowerPercent(int newHealPower) { healPowerPercent = newHealPower; }

    void use(Mythikin &patient);
};