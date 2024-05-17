#include "Item.h"

#pragma once

class Potion : protected Item
{
    unsigned healPower;

public:
    Potion(string name, unsigned quant, unsigned cap, int healPower) : Item(name, quant, cap), healPower(healPower) {}

    unsigned getHealPower() const { return healPower; }

    void changeHealPower(int newHealPower) { healPower = newHealPower; }

    void use(Mythikin &);
};