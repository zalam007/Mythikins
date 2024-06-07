#include "Item.h"

#pragma once

class Mythicube : public Item
{
    unsigned catchRate;                   // int of how easy it is to catch a Mythikin. 1 is default (catch based on health and chance), 2 is half is likely
    Mythikin *capturedMythikin = nullptr; // holds the captured Mythikin if successfully caught (nullptr if not)

public:
    // Constructor, extension of item class
    Mythicube(string name, unsigned quant, unsigned cap, unsigned price, unsigned rate)
        : Item(name, quant, cap, price), catchRate(rate) {}

    // Default constructor
    Mythicube() : Item("Mythicube", 1, 1, 100), catchRate(1), capturedMythikin(nullptr) {}

    // Destructor
    ~Mythicube() { delete capturedMythikin; } // deletes the captured Mythikin

    // Getters
    unsigned getCatchRate() const { return catchRate; } // returns the catch rate
    Mythikin *getCapturedMythikin() const { return capturedMythikin; } // returns nullpointer if no Mythikin

    // Setters
    void emptyMythicube() { capturedMythikin = nullptr; } // sets Mythicube pointer to null

    void setCatchRate(unsigned newRate) { catchRate = newRate; } // sets the catch rate

    // If calculatedToBeCaught==true catches the Wild-Mythikin and stores it in the capturedMythikin pointer
    void use(Mythikin &victim) override;

private:
    bool calculatedToBeCaught(Mythikin &victim) const; // helper function, calculates if the catch will be successful
};
