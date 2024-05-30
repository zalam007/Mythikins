#pragma once

#include <string>
#include "Mythikin.h"



using namespace std;

class Item
{
protected:
    string name;
    unsigned quantity;
    unsigned capacity;

public:
    Item(string name, unsigned quant, unsigned cap) : name(name), quantity(quant), capacity(cap)
    {
        // capacity can not be less that quanitity
        if (capacity < quantity)
        {
            capacity = quantity;
        }
    };

    // Accessor methods
    string getName() const { return name; }

    unsigned getQuantity() const { return quantity; }

    unsigned getCapacity() const { return capacity; }

    // Mutator methods
    void nameItem(string newName) { name = newName; }

    void changeQuantity(unsigned newQuant)
    {
        if (newQuant >= 0)
        {
            quantity = newQuant;
        }
    }

    void changeCapacity(unsigned newCap)
    {
        if (newCap >= quantity && newCap >= 0)
        {
            capacity = newCap;
        }
    }

    virtual void use(Mythikin&) = 0;
};