#include "Item.h"

#pragma once

class Mythicube : protected Item
{
    unsigned catchRate;         //influence how easier it is to catch a Mythikin
    Mythikin* capturedMythikin = nullptr; //holds the captured Mythikin if successfully caught

public:
    Mythicube(string, unsigned, unsigned, unsigned);

    // default cube
    Mythicube() : Item("Regular Mythicube", 1, 1), catchRate(1), capturedMythikin(nullptr) {}

    ~Mythicube(){delete capturedMythikin;}

    unsigned getCatchRate() const { return catchRate; }

    Mythikin* getMythikin() const { 
        if(capturedMythikin) {
            return capturedMythikin;
        }
    }

    void use(Mythikin &) override;

private:
    bool isCaught(Mythikin &) const; // helper function
};