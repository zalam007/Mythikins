#include "BattleItem.h"

#pragma once

class Potion : public BattleItem
{
    double healPowerPercent;

public:
    Potion(string name, unsigned quant, unsigned cap, unsigned price, double healPower) : BattleItem(name, quant, cap, price), healPowerPercent(healPower) {}

    // default constructor
    Potion() : BattleItem("Potion", 1, 1, 200), healPowerPercent(25.0) {}

    ~Potion() {}

    const unsigned getHealPowerPercent() const { return healPowerPercent; }

    void setHealPowerPercent(int newHealPower) { healPowerPercent = newHealPower; }

    virtual void use(Mythikin &patient);
};