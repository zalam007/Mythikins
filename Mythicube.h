#include "Item.h"

#pragma once

class Mythicube : protected Item
{
    unsigned catchRate;                     //int of how easy it is to catch a Mythikin. 1 is default (catch based on health and chance), 2 is half is likely
    Mythikin* capturedMythikin = nullptr;   //holds the captured Mythikin if successfully caught (nullptr if not)

public:
    //Constructor, extension of item class
    Mythicube::Mythicube(string name, unsigned quant, unsigned cap, unsigned rate)  //TODO PRICE
                    : Item(name, quant, cap), catchRate(rate){}

    //Default constructor
    Mythicube() : Item("Mythicube", 1, 1), catchRate(1), capturedMythikin(nullptr) {}

    //Destructor
    ~Mythicube() { delete capturedMythikin; }

    //Getters
    unsigned getCatchRate() const { return catchRate; }
    Mythikin* getCapturedMythikin() const { return capturedMythikin; }  //returns nullpointer if no Mythikin
    //Setter
    void emptyMythicube(){ capturedMythikin = nullptr; } // sets Mythicube pointer to null

    //Calls calculatedToBeCaught to be caught and uses the Mythicube to catch it, stores the Mythikin in the capturedMythikin pointer
    void use(Mythikin& victim) override;

private:
    bool calculatedToBeCaught(Mythikin& victim) const; // helper function, calculates if the catch will be successful
};