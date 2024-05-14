#include "Item.h"

#pragma once

class Mythicube : protected Item
{
    unsigned catchRate;

public:
    Mythicube(string, unsigned, unsigned, unsigned);

    // default cube
    Mythicube() : Item("Regular Mythicube", 1, 1), catchRate(1) {}

    unsigned getCatchRate() const { return catchRate; }

    void use(Mythikin &) override;

private:
    bool caught(Mythikin &) const; // helper function
};