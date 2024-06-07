#include "Item.h"

#pragma once

class Potion : public Item
{
    double healPowerPercent;

public:
    Potion(string name, unsigned quant, unsigned cap, unsigned price, double healPower) : Item(name, quant, cap, price), healPowerPercent(healPower) {}

    // default constructor
    Potion() : Item("Potion", 1, 1, 200), healPowerPercent(25.0) {}

    ~Potion() {}

    const unsigned getHealPowerPercent() const { return healPowerPercent; }

    void setHealPowerPercent(int newHealPower) { healPowerPercent = newHealPower; }

    virtual void use(Mythikin &patient);
};